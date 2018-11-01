import Vue from 'vue';
import Vuex from 'vuex'
import Router from '../router/router';
import Store from '../store/store';
import Header from '../components/layouts/Header.vue';
import * as Bootstrap from 'bootstrap-umi';
import 'bootstrap-umi/dist/css/bootstrap.css';

Vue.use(Vuex);
Vue.use(Bootstrap);

const app = new Vue({
    el: '#app',
    router: Router,
    store: Store,
    components: {
        'nav-bar': Header,
    }
})