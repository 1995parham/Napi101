/*
 * +===============================================
 * | Author:        Parham Alvani (parham.alvani@gmail.com)
 * |
 * | Creation Date: 09-06-2017
 * |
 * | File Name:     bye.js
 * +===============================================
 */
const bye = require('./build/Release/bye');

console.log(bye.byeASync());
console.log(bye.byeSync());
