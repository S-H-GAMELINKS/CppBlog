<template>
<div class="container">
    <div class="input-group">
        <div class="input-group-append">
            <span class="input-group-text">Title</span>
        </div>
        <input type="text" class="form-control" v-model="title" placeholder="Input blog title..."> 
    </div>
    <div class="input-group">
        <div class="input-group-append">
            <span class="input-group-text">Content</span>
        </div>
        <textarea v-model="content" class="form-control" placeholder="Input blog content..."></textarea>
    </div>
    <p>
        <button type="button" class="btn btn-primary" v-on:click="updateBlog">Update</button>
    </p>
</div>    
</template>

<script>

import router from '../../router/router';

export default {
    data: function() {
        return {
            title: "",
            content: ""
        }
    },
    mounted: function() {
        this.getBlogs();
    },
    methods: {
        getBlogs: function() {
            const path = String(this.$route.path).replace(/blogs\/edit/, '');
            
            const data = this.$store.state.database.ref('cppblog' + path);
            
            data.on("value", (snapshot) => {
                const blog = Object.entries(snapshot.val());

                this.title = blog[1][1];

                this.content = blog[0][1]

            }, (errorObject) => {
                console.log("The read failed: " + errorObject.code);
            })
        },
        updateBlog: function() {

            const path = String(this.$route.path).replace(/blogs\/edit/, '');

            const data = this.$store.state.database.ref('cppblog' + path);

            data.set({
                title: this.title,
                content: this.content
            });
            this.title = "";
            this.content = "";

            router.push({path: '/blogs'});
        }
    }

}
</script>