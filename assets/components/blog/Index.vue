<template>
<div>
    <div class="container">
        <p v-for="(blog, key, index) in blogs" :key=index>
            <router-link :to="{name: 'blogs', params: {id: blog.id}}">{{blog.title}}</router-link>
        </p>
    </div>
    <div class="container">
        <router-link to="/blogs/create">Create</router-link>
    </div>
</div>
</template>

<script>

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
            const data = this.$store.state.database.ref('cppblog');
            data.on("value", (snapshot) => {
                const blogs = Object.entries(snapshot.val());
                
                this.blogs.length = 0;
                for(var i = 0; i < blogs.length; i++) {
                    this.blogs.push({id: blogs[i][0], title: blogs[i][1].title});
                }
            }, (errorObject) => {
                console.log("The read failed: " + errorObject.code);
            })         
        }
    }

}
</script>