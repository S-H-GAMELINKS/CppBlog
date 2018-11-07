<template>
<div class="container">
    <div v-if="!this.$store.state.session">
    <div class="input-group">
        <div class="input-group-append">
            <span class="input-group-text">mail</span>
        </div>
        <input type="text" class="form-control" v-model="mail" placeholder="Input your mail..."> 
    </div>
    <div class="input-group">
        <div class="input-group-append">
            <span class="input-group-text">pass</span>
        </div>
        <input v-model="pass" class="form-control" type="password" placeholder="Input your pass..."></textarea>
    </div>
    <p>
        <button type="button" class="btn btn-primary" v-on:click="loginBlog">Login</button>
    </p>
    </div>
    <div v-else>
        <h1> You Are Login Now!! </h1> 
    </div>
</div>    
</template>

<script>

import router from '../../router/router';

export default {
    data: function() {
        return {
            mail: "",
            pass: "",
        }
    },
    moutnted: function() {
        this.userLogin();
    },
    methods: {
        userLogin: function() {

            const firebase = this.$store.state.firebase;

            firebase.auth().onAuthStateChanged((response) => {
                if (response) {
                    this.$store.commit('getSession', true);
                    router.push({path: '/'});
                }
            }, (error) => {
                console.log(error);
            });
        },
        loginBlog: function() {

            const firebase = this.$store.state.firebase;

            firebase.auth().signInWithEmailAndPassword(this.mail, this.pass).then((response) => {
                console.log(response);
            }, (error) => {
                console.log(error)
            })

            this.userLogin();
        }
    }
}
</script>
>