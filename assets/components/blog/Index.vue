<template>
<div>
    <div class="container">
        <p v-for="(blog, key, index) in blogs" :key=index>
            {{blog.title}}
        <p>
    </div>
</div>
</template>

<script>

import axios from 'axios'

export default {
    data: function() {
        return {
            blogs: []
        }
    },
    mounted: function() {
        this.getBlogs();
    },
    methods: {
        getBlogs: function() {
            const data = database.ref('cppblog');
            data.on("value", (snapshot) => {
                const blogs = Object.entries(snapshot.val());
                
                this.blogs.length = 0;
                for(var i = 0; i < blogs.length; i++) {
                    this.blogs.push({id: blog[i][0], title: blog[i][1].title});
                }
            }, (errorObject) => {
                console.log("The read failed: " + errorObject.code);
            })         
        }
    }

}
</script>