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
        <button type="button" class="btn btn-primary" v-on:click="createBlog">Create</button>
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
    methods: {
        createBlog: function() {
            this.$store.state.database.ref('cppblog').push({
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