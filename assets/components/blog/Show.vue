<template>
<div class="container">
    {{content}}
    {{title}}
</div>    
</template>

<script>

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
            const path = String(this.$route.path).replace(/blogs/, '');
            
            const data = this.$store.state.database.ref('cppblog' + path);

            console.log(data);
            
            data.on("value", (snapshot) => {
                const blog = Object.entries(snapshot.val());

                this.title = blog[0][1];

                this.content = blog[0][2]

                console.log(blog);
            }, (errorObject) => {
                console.log("The read failed: " + errorObject.code);
            })
        }
    }
}
</script>
