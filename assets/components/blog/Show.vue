<template>
<div class="container">
    <h1>{{title}}</h1>
    <vue-simple-markdown :source="content"> {{content}} </vue-simple-markdown>
</div>    
</template>

<script>

import { VueSimpleMarkdown } from 'vue-simple-markdown';

export default {
    data: function() {
        return {
            title: "",
            content: ""
        }
    },
    components: {
        'vue-simple-markdown': VueSimpleMarkdown
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

                console.log(blog);

                this.title = blog[1][1];

                this.content = blog[0][1]

                console.log(blog);
            }, (errorObject) => {
                console.log("The read failed: " + errorObject.code);
            })
        }
    }
}
</script>
