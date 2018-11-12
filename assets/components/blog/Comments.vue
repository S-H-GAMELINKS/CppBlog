<template>
    <div class="container">
        <div class="input-group">
            <div class="input-group-append">
                <span class="input-group-text">Comment</span>
            </div>
            <textarea v-model="comment" class="form-control" placeholder="Input your comment..."></textarea>
        </div>
        <p>
            <button type="button" class="btn btn-primary" v-on:click="createComments">Submit</button>
        </p>
        <div v-for="(comment, key, index) in comments" :key=index>
            <vue-simple-markdown :source="comment" v-highlight>{{comment}}</vue-simple-markdown>
        </div>
    </div>
</template>

<script>

import { VueSimpleMarkdown } from 'vue-simple-markdown';

export default {
    data: function() {
        return {
            comment: "",
            comments: []
        }
    },
    components: {
        'vue-simple-markdown': VueSimpleMarkdown
    },
    mounted: function() {
        this.getComments();
    },
    methods: {
        getComments: function() {
            const path = String(this.$route.path).replace(/blogs/, '');
            
            const data = this.$store.state.database.ref('cppblog' + path);
            
            data.on("value", (snapshot) => {

                const comments = Object.entries(snapshot.val());

                if (comments[0][0] === "comments") {

                    const allComments = this.$store.state.database.ref('cppblog' + path + '/comments');

                    allComments.on("value", (snap) => {

                        const commentsData = Object.entries(snap.val())

                        this.comments.length = 0;

                        for(var i = 0; i < commentsData.length; i++) {
                            this.comments.push(commentsData[i][1].comment);
                        }
                    }, (error) => {
                        console.log(error);
                    })
                }
                console.log(comments);
            }, (errorObject) => {
                console.log("The read failed: " + errorObject.code);
            })
        },
        createComments: function() {
            const path = String(this.$route.path).replace(/blogs/, '');

            this.$store.state.database.ref('cppblog' + path + '/comments').push({
                comment: this.comment
            });
            this.comment = "";
        }
    }
}
</script>

