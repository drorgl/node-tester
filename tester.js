console.log("starting");

var addon = null;
var aoRelease = null;
var aoDebug = null;

if (addon == null){
	try{
		addon = require('./build/Release/tester');
	}catch (e){
		aoRelease = e;
	}
}

if (addon == null){
	try{
		addon = require('./build/Debug/tester');
	}catch (e){
		aoDebug = e;
	}
}

console.log("addon",addon);

if (addon == null){
	console.log(aoRelease,aoDebug);
}




//console.log("addon.test()", JSON.stringify(addon.test(), null, "\t"));
//
//console.log("addon.test(1)", addon.test(1));
//console.log("addon.test('1')", addon.test('1'));
//console.log("addon.test('1.x')", addon.test('1.x'));
//console.log("addon.test(1)", addon.test(1.0));
//
//console.log("addon.test(1.1)", addon.test(1.1));
//
//console.log("addon.test(\"hello\")", addon.test("hello"));
//
//console.log("addon.test([\"hello\"])", addon.test(["hello"]));
//
//console.log("addon.test(function(x){})", addon.test(function (x) { }));
//
//console.log("addon.test(console.log)", addon.test(console.log));
//
//console.log("addon.test(new Buffer(0))", addon.test(new Buffer(0)));

//
//console.log("addon.test(9223372036854775807)", addon.test(9223372036854775807));
//
//
//var bc = new addon.base_class();
//console.log("new addon.base_class()", bc);
//var cc = new addon.child_class();
//console.log("new addon.child_class()", JSON.stringify(addon.test(cc), null, "\t"));

//var ccc = new addon.child_child_class();
//console.log("new addon.child_child_class()", JSON.stringify(addon.test(ccc), null, "\t"));


//
//console.log("bc instanceof base_class",addon.base_class.InstanceOf(bc));
//console.log("cc instanceof base_class",addon.base_class.InstanceOf(cc));
//console.log("obj instanceof base_class",addon.base_class.InstanceOf({}));
//
//console.log("bc instanceof  child_class",addon.child_class.InstanceOf(bc));
//console.log("cc instanceof  child_class",addon.child_class.InstanceOf(cc));
//console.log("obj instanceof child_class",addon.child_class.InstanceOf({}));
//
//
//console.log("addon.test(cc)",JSON.stringify(addon.test(cc), null, "\t") );
//


//console.log("addon.test(addon.base_class)", JSON.stringify(addon.test(addon.base_class), null, "\t"));
//
//var bc = new addon.base_class();
//
//console.log("addon.test(addon.base_class.test_member_function)", JSON.stringify(bc.test_member_function(), null, "\t"));
//
//console.log("addon.test(addon.base_class.test_static_function)", JSON.stringify(addon.base_class.test_static_function(), null, "\t"));
////
//console.log("addon.test(function () { alert(\"x\");})",JSON.stringify(addon.test(function () { alert("x");}), null, "\t"));

