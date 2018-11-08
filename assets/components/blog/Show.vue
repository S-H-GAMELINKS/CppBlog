<template>
    <div class="container">
        <h1>{{title}}</h1>
        <vue-simple-markdown :source="content" v-highlight>{{content}}</vue-simple-markdown>
        <comments></comments>
    </div>    
</template>

<script>

import { VueSimpleMarkdown } from 'vue-simple-markdown';
import Comments from './Comments.vue';

export default {
    data: function() {
        return {
            title: "",
            content: ""
        }
    },
    components: {
        'vue-simple-markdown': VueSimpleMarkdown,
        'comments': Comments
    },
    mounted: function() {
        this.getBlogs();
    },
    methods: {
        getBlogs: function() {
            const path = String(this.$route.path).replace(/blogs/, '');
            
            const data = this.$store.state.database.ref('cppblog' + path);
            
            data.on("value", (snapshot) => {
                const blog = Object.entries(snapshot.val());

                for(var i = 0; i < blog.length; i++) {
                    if(blog[i][0] === "content") {
                        this.content = blog[i][1]
                    } else if (blog[i][0] === "title") {
                        this.title = blog[i][1];
                    }
                }

                console.log(blog)

            }, (errorObject) => {
                console.log("The read failed: " + errorObject.code);
            })
        }
    }
}
</script>
