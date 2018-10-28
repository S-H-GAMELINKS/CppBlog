import Vue from 'vue';
import Router from './router/router';
import * as Bootstrap from 'bootstrap-umi';
import 'bootstrap-umi/dist/css/bootstrap.css';

Vue.use(Bootstrap);

const app = new Vue({
    el: '#app',
    router: Router,
    data: function() {
        return {
            message: "Hello!"
        }
    }
})