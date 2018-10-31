import Vue from 'vue';
import VueRouter from 'vue-router';
import Index from '../components/web/Index.vue';
import About from '../components/web/About.vue';
import Contact from '../components/web/Contact.vue';
import Blogs from '../components/blog/Index.vue';
import Create from '../components/blog/Create.vue';
import Show from '../components/blog/Show.vue';

Vue.use(VueRouter)

export default new VueRouter({
  mode: 'history',
  routes: [
    { path: '/', component: Index },
    { path: '/about', component: About },
    { path: '/contact', component: Contact },
    { path: '/blogs', component: Blogs },
    { path: '/blogs/create', component: Create },
    { path: '/blogs/:id', component: Show, name: 'blogs'},
  ],
})