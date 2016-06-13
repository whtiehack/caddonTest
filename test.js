/**
 * Created by mac on 16/5/17.
 */

// var bindings = require('bindings')
// var addon = bindings('myaddon');
//
// console.log(addon.hello(2000,function(){
//     console.log('aaaaaaa');
// }));


var addon = require('bindings')('myaddon');

console.log(addon.hello()); // 'world'

console.log('addon add:', addon.add(10,20));

addon.callback(function(arg){
                    console.log(' addon callback ret:',arg);
               });


console.log('addon objectfactory:',addon.objectfactory('test obj new'));

console.log('callback end');


var fun = addon.createFunction();
console.log("xxfun cfun:",fun);

console.log(fun());


var myobj = addon.MyObject();
console.log('myobject',myobj.value(),myobj.plusOne(),myobj.plusOne(),myobj.multiply(10).value());
console.log('all end');


var createFactory = addon.ObjCreateObject;

myobj = createFactory(10);
console.log(myobj,myobj.plusOne());

console.log('factory end');



