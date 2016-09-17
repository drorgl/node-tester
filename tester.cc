#include <node.h>
#include <v8.h>
#include "node_modules/nan/nan.h"

using namespace v8;

void dumpValue(v8::Local<v8::Object> into, v8::Local<v8::Value> val,bool nesting);
void dumpObject(v8::Local<v8::Object> into, v8::Local<v8::Object> obj, bool nesting);
void dumpFunction(v8::Local<v8::Object> into, v8::Local<v8::Function> func);
void dumpScriptOrigin(v8::Local<v8::Object> into, ScriptOrigin scro);
void dumpScriptOriginOptions(v8::Local<v8::Object> into, v8::ScriptOriginOptions & soo);
void dumpString(v8::Local<v8::Object> into, v8::Local<v8::String> str);
void dumpArray(v8::Local<v8::Object> into, v8::Local<v8::Array> arr);
void dumpArrayBuffer(v8::Local<v8::Object> into, v8::Local<v8::ArrayBuffer> arr);
void dumpArrayBufferView(v8::Local<v8::Object> into, v8::Local<v8::ArrayBufferView> abv);
void dumpMap(v8::Local<v8::Object> into, v8::Local<v8::Map> str);
void dumpRegExp(v8::Local<v8::Object> into, v8::Local<v8::RegExp> str);
void dumpExternal(v8::Local<v8::Object> into, v8::Local<v8::External> str);
void dumpTypedArray(v8::Local<v8::Object> into, v8::Local<v8::TypedArray> ta);
void dumpPromise(v8::Local<v8::Object> into, v8::Local<v8::Promise> promise);
void dumpProxy(v8::Local<v8::Object> into, v8::Local<v8::Proxy> prx);
void dumpSymbol(v8::Local<v8::Object> into, v8::Local<v8::Symbol> str);
void dumpSharedArrayBuffer(v8::Local<v8::Object> into, v8::Local<v8::SharedArrayBuffer> sab);
void dumpSet(v8::Local<v8::Object> into, v8::Local<v8::Set> str);
void dumpDate(v8::Local<v8::Object> into, v8::Local<v8::Date> date);




void dumpValue(v8::Local<v8::Object> into, v8::Local<v8::Value> val, bool nesting = true) {
	into->Set(Nan::New("IsUndefined").ToLocalChecked(), Nan::New(val->IsUndefined()));
	into->Set(Nan::New("IsNull").ToLocalChecked(), Nan::New(val->IsNull()));
	into->Set(Nan::New("IsTrue").ToLocalChecked(), Nan::New(val->IsTrue()));
	into->Set(Nan::New("IsFalse").ToLocalChecked(), Nan::New(val->IsFalse()));
	into->Set(Nan::New("IsName").ToLocalChecked(), Nan::New(val->IsName()));
	
	into->Set(Nan::New("IsString").ToLocalChecked(), Nan::New(val->IsString()));
	if (nesting && val->IsString()) {
		dumpString(into, val.As<v8::String>());
	}

	into->Set(Nan::New("IsSymbol").ToLocalChecked(), Nan::New(val->IsSymbol()));
	if (nesting && val->IsSymbol()) {
		dumpSymbol(into,val.As<v8::Symbol>());
	}

	into->Set(Nan::New("IsFunction").ToLocalChecked(), Nan::New(val->IsFunction()));
	if (nesting && val->IsFunction()) {
		dumpFunction(into,val.As<v8::Function>());
	}

	into->Set(Nan::New("IsArray").ToLocalChecked(), Nan::New(val->IsArray()));
	if (nesting && val->IsArray()) {
		dumpArray(into, val.As<v8::Array>());
	}

	into->Set(Nan::New("IsObject").ToLocalChecked(), Nan::New(val->IsObject()));
	if (nesting && val->IsObject()) {
		dumpObject(into, val.As<v8::Object>(),true);
	}

	into->Set(Nan::New("IsBoolean").ToLocalChecked(), Nan::New(val->IsBoolean()));
	into->Set(Nan::New("IsNumber").ToLocalChecked(), Nan::New(val->IsNumber()));
	into->Set(Nan::New("IsExternal").ToLocalChecked(), Nan::New(val->IsExternal()));
	if (nesting && val->IsExternal()) {
		dumpExternal(into, val.As<v8::External>());
	}

	into->Set(Nan::New("IsInt32").ToLocalChecked(), Nan::New(val->IsInt32()));
	into->Set(Nan::New("IsUint32").ToLocalChecked(), Nan::New(val->IsUint32()));
	into->Set(Nan::New("IsDate").ToLocalChecked(), Nan::New(val->IsDate()));
	if (nesting && val->IsDate()) {
		dumpDate(into, val.As<v8::Date>());
	}

	into->Set(Nan::New("IsArgumentsObject").ToLocalChecked(), Nan::New(val->IsArgumentsObject()));
	into->Set(Nan::New("IsBooleanObject").ToLocalChecked(), Nan::New(val->IsBooleanObject()));
	into->Set(Nan::New("IsNumberObject").ToLocalChecked(), Nan::New(val->IsNumberObject() ));
	into->Set(Nan::New("IsStringObject").ToLocalChecked(), Nan::New(val->IsStringObject() ));
	into->Set(Nan::New("IsSymbolObject").ToLocalChecked(), Nan::New(val->IsSymbolObject() ));
	into->Set(Nan::New("IsNativeError").ToLocalChecked(), Nan::New(val->IsNativeError()));
	into->Set(Nan::New("IsRegExp").ToLocalChecked(), Nan::New(val->IsRegExp()));
	if (nesting && val->IsRegExp()) {
		dumpRegExp(into, val.As<v8::RegExp>());
	}

	into->Set(Nan::New("IsGeneratorFunction").ToLocalChecked(), Nan::New(val->IsGeneratorFunction()));
	into->Set(Nan::New("IsGeneratorObject").ToLocalChecked(), Nan::New(val->IsGeneratorObject()));
	into->Set(Nan::New("IsPromise").ToLocalChecked(), Nan::New(val->IsPromise()));
	if (nesting && val->IsPromise()) {
		dumpPromise(into, val.As<v8::Promise>());
	}

	into->Set(Nan::New("IsMap").ToLocalChecked(), Nan::New(val->IsMap()));
	if (nesting && val->IsMap()) {
		dumpMap(into, val.As<v8::Map>());
	}

	into->Set(Nan::New("IsSet").ToLocalChecked(), Nan::New(val->IsSet()));
	if (nesting && val->IsSet()) {
		dumpSet(into, val.As<v8::Set>());
	}

	into->Set(Nan::New("IsMapIterator").ToLocalChecked(), Nan::New(val->IsMapIterator()));
	into->Set(Nan::New("IsSetIterator").ToLocalChecked(), Nan::New(val->IsSetIterator()));
	into->Set(Nan::New("IsWeakMap").ToLocalChecked(), Nan::New(val->IsWeakMap()));
	into->Set(Nan::New("IsWeakSet").ToLocalChecked(), Nan::New(val->IsWeakSet()));
	into->Set(Nan::New("IsArrayBuffer").ToLocalChecked(), Nan::New(val->IsArrayBuffer()));
	if (nesting && val->IsArrayBuffer()) {
		dumpArrayBuffer(into, val.As<v8::ArrayBuffer>());
	}

	into->Set(Nan::New("IsArrayBufferView").ToLocalChecked(), Nan::New(val->IsArrayBufferView()));
	if (nesting && val->IsArrayBufferView()) {
		dumpArrayBufferView(into, val.As<v8::ArrayBufferView>());
	}

	into->Set(Nan::New("IsTypedArray").ToLocalChecked(), Nan::New(val->IsTypedArray()));
	if (nesting && val->IsTypedArray()) {
		dumpTypedArray(into, val.As<v8::TypedArray>());
	}

	into->Set(Nan::New("IsUint8Array").ToLocalChecked(), Nan::New(val->IsUint8Array()));
	into->Set(Nan::New("IsUint8ClampedArray").ToLocalChecked(), Nan::New(val->IsUint8ClampedArray()));
	into->Set(Nan::New("IsInt8Array").ToLocalChecked(), Nan::New(val->IsInt8Array()));
	into->Set(Nan::New("IsUint16Array").ToLocalChecked(), Nan::New(val->IsUint16Array()));
	into->Set(Nan::New("IsInt16Array").ToLocalChecked(), Nan::New(val->IsInt16Array()));
	into->Set(Nan::New("IsUint32Array").ToLocalChecked(), Nan::New(val->IsUint32Array()));
	into->Set(Nan::New("IsInt32Array").ToLocalChecked(), Nan::New(val->IsInt32Array()));
	into->Set(Nan::New("IsFloat32Array").ToLocalChecked(), Nan::New(val->IsFloat32Array()));
	into->Set(Nan::New("IsFloat64Array").ToLocalChecked(), Nan::New(val->IsFloat64Array()));
	//into->Set(Nan::New("IsFloat32x4").ToLocalChecked(), Nan::New(val->IsFloat32x4()));
	into->Set(Nan::New("IsDataView").ToLocalChecked(), Nan::New(val->IsDataView()));
	into->Set(Nan::New("IsSharedArrayBuffer").ToLocalChecked(), Nan::New(val->IsSharedArrayBuffer()));
	if (nesting && val->IsSharedArrayBuffer()) {
		dumpSharedArrayBuffer(into, val.As<v8::SharedArrayBuffer>());
	}


	into->Set(Nan::New("IsProxy").ToLocalChecked(), Nan::New(val->IsProxy()));
	if (nesting && val->IsProxy()) {
		dumpProxy(into, val.As<v8::Proxy>());
	}

	 into->Set(Nan::New("ToBoolean").ToLocalChecked(), val->ToBoolean());
	 into->Set(Nan::New("ToNumber").ToLocalChecked(), val->ToNumber());
	 into->Set(Nan::New("ToString").ToLocalChecked(), val->ToString());
	 into->Set(Nan::New("ToDetailString").ToLocalChecked(), val->ToDetailString());
	 into->Set(Nan::New("ToObject").ToLocalChecked(), val->ToObject());
	 into->Set(Nan::New("ToInteger").ToLocalChecked(), val->ToInteger());
	 into->Set(Nan::New("ToUint32").ToLocalChecked(), val->ToUint32());
	 into->Set(Nan::New("ToInt32").ToLocalChecked(), val->ToInt32());


	 into->Set(Nan::New("BooleanValue").ToLocalChecked(), Nan::New(val->BooleanValue()));
	 into->Set(Nan::New("NumberValue").ToLocalChecked(), Nan::New(val->NumberValue()));
	 into->Set(Nan::New("IntegerValue").ToLocalChecked(), Nan::New((double)val->IntegerValue()));
	 into->Set(Nan::New("Uint32Value").ToLocalChecked(), Nan::New(val->Uint32Value()));
	 into->Set(Nan::New("Int32Value").ToLocalChecked(), Nan::New(val->Int32Value()));

}

void dumpObject(v8::Local<v8::Object> into, v8::Local<v8::Object> obj, bool nesting = true) {
	auto propertyNames = obj->GetOwnPropertyNames();
	auto arrInto = Nan::New<v8::Array>();
	
	into->Set(Nan::New("PropertyNames").ToLocalChecked(), arrInto);
	dumpArray(arrInto, propertyNames);

	
	into->Set(Nan::New("GetConstructorName").ToLocalChecked(), obj->GetConstructorName());
	into->Set(Nan::New("InternalFieldCount").ToLocalChecked(), Nan::New(obj->InternalFieldCount()));
	into->Set(Nan::New("HasNamedLookupInterceptor").ToLocalChecked(), Nan::New(obj->HasNamedLookupInterceptor()));
	into->Set(Nan::New("HasIndexedLookupInterceptor").ToLocalChecked(), Nan::New(obj->HasIndexedLookupInterceptor()));
	into->Set(Nan::New("GetIdentityHash").ToLocalChecked(), Nan::New(obj->GetIdentityHash()));
	into->Set(Nan::New("IsCallable").ToLocalChecked(), Nan::New(obj->IsCallable()));

	if (nesting) {
	//if (*Nan::Utf8String( obj->GetConstructorName()) != "Object"){
		auto proto = Nan::New<v8::Object>();
		dumpValue(proto, obj->GetPrototype(), false);
		dumpObject(proto, obj->GetPrototype()->ToObject(), false);
		into->Set(Nan::New("GetPrototype").ToLocalChecked(), proto);
	}

	/*
	T* unwrap(Handle<Value> handle){
		if (!handle->IsObject()) return NULL;
		Handle<Object> o = Handle<Object>::Cast(handle);
		if (o->InternalFieldCount() == 0) return NULL;
		if (o->FindInstanceInPrototypeChain(tpl).IsEmpty()) return NULL;
		return static_cast<T*>(o->GetPointerFromInternalField(0));
	}
	*/

}

void dumpFunction(v8::Local<v8::Object> into, v8::Local<v8::Function> func) {
	into->Set(Nan::New("GetName").ToLocalChecked(), func->GetName());
	into->Set(Nan::New("GetInferredName").ToLocalChecked(), func->GetInferredName());
	into->Set(Nan::New("GetDebugName").ToLocalChecked(), func->GetDebugName());
	into->Set(Nan::New("GetDisplayName").ToLocalChecked(), func->GetDisplayName());
	into->Set(Nan::New("GetScriptLineNumber").ToLocalChecked(), Nan::New(func->GetScriptLineNumber()));
	into->Set(Nan::New("GetScriptColumnNumber").ToLocalChecked(), Nan::New(func->GetScriptColumnNumber()));
	into->Set(Nan::New("IsBuiltin").ToLocalChecked(), Nan::New(func->IsBuiltin()));
	into->Set(Nan::New("ScriptId").ToLocalChecked(), Nan::New(func->ScriptId()));
	into->Set(Nan::New("GetBoundFunction").ToLocalChecked(), func->GetBoundFunction());
	//
	auto so = Nan::New<v8::Object>();
	into->Set(Nan::New("GetScriptOrigin").ToLocalChecked(), so);
	dumpScriptOrigin(so, func->GetScriptOrigin());
	
}

//TODO: figure out why script origin is null
void dumpScriptOrigin(v8::Local<v8::Object> into, ScriptOrigin scro) {
		//assert(false);
		
		if (!scro.ResourceName().IsEmpty()) {
			into->Set(Nan::New("ResourceName").ToLocalChecked(), scro.ResourceName());
		}

		if (!scro.ResourceLineOffset().IsEmpty()) {
			into->Set(Nan::New("ResourceLineOffset").ToLocalChecked(), scro.ResourceLineOffset());
		}

		if (!scro.ResourceColumnOffset().IsEmpty()) {
			into->Set(Nan::New("ResourceColumnOffset").ToLocalChecked(), scro.ResourceColumnOffset());
		}

		if (!scro.ScriptID().IsEmpty()) {
			into->Set(Nan::New("ScriptID").ToLocalChecked(), scro.ScriptID());
		}

		if (!scro.SourceMapUrl().IsEmpty()) {
			into->Set(Nan::New("SourceMapUrl").ToLocalChecked(), scro.SourceMapUrl());
		}

		//if (scro.Options()) {
			auto soo = Nan::New<v8::Object>();
			dumpScriptOriginOptions(soo, scro.Options());
			into->Set(Nan::New("Options").ToLocalChecked(), soo);
		//}
	//}
}

void dumpScriptOriginOptions(v8::Local<v8::Object> into, v8::ScriptOriginOptions & soo) {
	into->Set(Nan::New("IsEmbedderDebugScript").ToLocalChecked(), Nan::New(soo.IsEmbedderDebugScript()));
	into->Set(Nan::New("IsSharedCrossOrigin").ToLocalChecked(), Nan::New(soo.IsSharedCrossOrigin()));
	into->Set(Nan::New("IsOpaque").ToLocalChecked(), Nan::New(soo.IsOpaque()));
	into->Set(Nan::New("Flags").ToLocalChecked(), Nan::New(soo.Flags()));
}

void dumpString(v8::Local<v8::Object> into, v8::Local<v8::String> str) {
	
	into->Set(Nan::New("Length").ToLocalChecked(), Nan::New(str->Length()));
	into->Set(Nan::New("Utf8Length").ToLocalChecked(), Nan::New(str->Utf8Length()));
	into->Set(Nan::New("IsOneByte").ToLocalChecked(), Nan::New(str->IsOneByte()));
	into->Set(Nan::New("ContainsOnlyOneByte").ToLocalChecked(), Nan::New(str->ContainsOnlyOneByte()));
	into->Set(Nan::New("IsExternal").ToLocalChecked(), Nan::New(str->IsExternal()));
	into->Set(Nan::New("IsExternalOneByte").ToLocalChecked(), Nan::New(str->IsExternalOneByte()));
}

void dumpArray(v8::Local<v8::Object> into, v8::Local<v8::Array> arr) {
	auto arrValues = Nan::New<v8::Array>();
	into->Set(Nan::New("ArrayValues").ToLocalChecked(), arrValues);
	for (auto i = 0; i < arr->Length(); i++) {
		auto val = Nan::New<v8::Object>();
		arrValues->Set(i, val);
		dumpValue(arrValues, arr->Get(i));
	}
}

void dumpArrayBuffer(v8::Local<v8::Object> into, v8::Local<v8::ArrayBuffer> arr) {
	auto arrBuf = Nan::New<v8::Object>();
	into->Set(Nan::New("ArrayBufferValue").ToLocalChecked(), arrBuf);

	arrBuf->Set(Nan::New("ByteLength").ToLocalChecked(), Nan::New((int)arr->ByteLength()));
	arrBuf->Set(Nan::New("IsNeuterable").ToLocalChecked(),Nan::New( arr->IsNeuterable()));

	auto contents = arr->GetContents();

	arrBuf->Set(Nan::New("Buffer").ToLocalChecked(),Nan::NewBuffer((char*)contents.Data(),(uint32_t)contents.ByteLength()).ToLocalChecked());
}

void dumpArrayBufferView(v8::Local<v8::Object> into, v8::Local<v8::ArrayBufferView> abv) {
	auto arrBufView = Nan::New<v8::Object>();
	into->Set(Nan::New("ArrayBufferView").ToLocalChecked(), arrBufView);

	arrBufView->Set(Nan::New("ByteOffset").ToLocalChecked(), Nan::New((int)abv->ByteOffset()));
	arrBufView->Set(Nan::New("ByteLength").ToLocalChecked(), Nan::New((int)abv->ByteLength()));
	arrBufView->Set(Nan::New("HasBuffer").ToLocalChecked(), Nan::New(abv->HasBuffer()));

	dumpArrayBuffer(arrBufView, abv->Buffer());
}

void dumpMap(v8::Local<v8::Object> into, v8::Local<v8::Map> str) {
}

void dumpRegExp(v8::Local<v8::Object> into, v8::Local<v8::RegExp> str) {
	into->Set(Nan::New("GetSource").ToLocalChecked(), str->GetSource());

	//TODO: regexp flags
	//into->Set(Nan::New("GetFlags").ToLocalChecked(), str->GetFlags()));
}


void dumpExternal(v8::Local<v8::Object> into, v8::Local<v8::External> str) {
	into->Set(Nan::New("Value").ToLocalChecked(), Nan::New((long)str->Value()));
}

void dumpTypedArray(v8::Local<v8::Object> into, v8::Local<v8::TypedArray> ta) { //IsFloat32Array,IsFloat64Array,IsInt16Array,IsInt32Array,IsInt8Array
	dumpArrayBufferView(into, ta);
}

void dumpPromise(v8::Local<v8::Object> into, v8::Local<v8::Promise> promise) { 
	into->Set(Nan::New("HasHandler").ToLocalChecked(), Nan::New(promise->HasHandler()));
}

void dumpProxy(v8::Local<v8::Object> into, v8::Local<v8::Proxy> prx) {
	auto target = Nan::New<v8::Object>();
	into->Set(Nan::New("GetTarget").ToLocalChecked(), target);
	dumpValue(target, prx->GetTarget());

	auto handler = Nan::New<v8::Object>();
	into->Set(Nan::New("GetHandler").ToLocalChecked(), handler);
	dumpValue(handler, prx->GetHandler());


	into->Set(Nan::New("IsRevoked").ToLocalChecked(), Nan::New(prx->IsRevoked()));
}

void dumpSymbol(v8::Local<v8::Object> into, v8::Local<v8::Symbol> str) {
	into->Set(Nan::New("Name").ToLocalChecked(), str->Name());
}

void dumpSharedArrayBuffer(v8::Local<v8::Object> into, v8::Local<v8::SharedArrayBuffer> sab) {
	auto arrBuf = Nan::New<v8::Object>();
	into->Set(Nan::New("ArrayBufferValue").ToLocalChecked(), arrBuf);

	arrBuf->Set(Nan::New("ByteLength").ToLocalChecked(), Nan::New((int)sab->ByteLength()));
	arrBuf->Set(Nan::New("IsExternal").ToLocalChecked(), Nan::New(sab->IsExternal()));

	auto contents = sab->GetContents();
	arrBuf->Set(Nan::New("Buffer").ToLocalChecked(), Nan::NewBuffer((char*)contents.Data(), contents.ByteLength()).ToLocalChecked());
}

void dumpSet(v8::Local<v8::Object> into, v8::Local<v8::Set> str) {
	//Size
	//AsArray
}

void dumpDate(v8::Local<v8::Object> into, v8::Local<v8::Date> date) {
	into->Set(Nan::New("ValueOf").ToLocalChecked(), Nan::New(date->ValueOf()));
}


NAN_METHOD(test) {
	auto retval = Nan::New<v8::Object>();
	retval->Set(Nan::New("Length").ToLocalChecked(),Nan::New( info.Length()));
	retval->Set(Nan::New("Data").ToLocalChecked(), info.Data());

	auto callObj = Nan::New<v8::Object>();
	dumpValue(callObj, info.Callee());
	retval->Set(Nan::New("Callee").ToLocalChecked(),callObj);

	retval->Set(Nan::New("IsConstructCall").ToLocalChecked(), Nan::New(info.IsConstructCall()));

	auto thisObj = Nan::New < v8::Object>();
	dumpValue(thisObj, info.This());
	retval->Set(Nan::New("This").ToLocalChecked(), thisObj);

	auto infoArray = Nan::New<v8::Array>();
	retval->Set(Nan::New("Info").ToLocalChecked(), infoArray);

	for (auto i = 0; i < info.Length(); i++) {
		auto infoObj = Nan::New<v8::Object>();
		infoArray->Set(i, infoObj);
		dumpValue(infoObj, info[i]);

			//missing in node 6.5 lib
	//		//infoObj->Set(Nan::New("IsFloat32x4").ToLocalChecked(),Nan::New( info[i]->IsFloat32x4()));
		
			//not working on string
	//		infoObj->Set(Nan::New("ToArrayIndex").ToLocalChecked(), (info[i]->ToArrayIndex()));

	}


	info.GetReturnValue().Set(retval);
}



class base_class : public Nan::ObjectWrap {
public:
	static NAN_METHOD(base_class::New) {

		base_class *cls = NULL;

		cls = new base_class();

		cls->Wrap(info.Holder());
		info.GetReturnValue().Set(info.Holder());
	}

	static NAN_METHOD(base_class::InstanceOf) {
		auto ft = Nan::New(constructor);
		if (ft->HasInstance(info[0])) {
			info.GetReturnValue().Set(Nan::New(true));
		}
		else {
			info.GetReturnValue().Set(Nan::New(false));
		}
	}

	//static NAN_METHOD(base_class::FindInstanceInPrototypeChain) {
		
		
	/*	auto o0 = Handle<Object>::Cast(info[0]);
		o0->*/

		
		//Handle<Object>::Cast(info[0])->FindInstanceInPrototypeChain(Nan::New(child_class::constructor))

		/*auto ft = Nan::New(constructor);
		if (ft->HasInstance(info[0])) {
			info.GetReturnValue().Set(Nan::New(true));
		}
		else {
			info.GetReturnValue().Set(Nan::New(false));
		}*/
	//}



	static Nan::Persistent<FunctionTemplate> base_class::constructor;

	static void Init(Handle<Object> target) {
		//Class
		Local<FunctionTemplate> ctor = Nan::New<FunctionTemplate>(base_class::New);
		constructor.Reset(ctor);
		ctor->InstanceTemplate()->SetInternalFieldCount(1);
		ctor->SetClassName(Nan::New("base_class").ToLocalChecked());

		Nan::SetMethod(ctor, "InstanceOf", InstanceOf);
		//Nan::SetMethod(ctor, "FindInstanceInPrototypeChain", FindInstanceInPrototypeChain);

		target->Set(Nan::New("base_class").ToLocalChecked(), ctor->GetFunction());
	}
};

Nan::Persistent<FunctionTemplate> base_class::constructor;

class child_class : public Nan::ObjectWrap {
public:
	static NAN_METHOD(child_class::New) {

		child_class *cls = NULL;

		cls = new child_class();

		cls->Wrap(info.Holder());
		info.GetReturnValue().Set(info.Holder());
	}



	static Nan::Persistent<FunctionTemplate> child_class::constructor;

	static NAN_METHOD(child_class::InstanceOf) {
		//Handle<Object>::Cast(info[0])->FindInstanceInPrototypeChain(Nan::New(child_class::constructor))


		auto ft = Nan::New(constructor);
		/*Handle<Object>::Cast(ft)->FindInstanceInPrototypeChain(child_class:constructor);
		Handle<Object>::Cast(info[0])->FindInstanceInPrototypeChain		(child_class:constructor)*/

		if (ft->HasInstance(info[0])) {
			info.GetReturnValue().Set(Nan::New(true));
		}
		else {
			info.GetReturnValue().Set(Nan::New(false));
		}
	}

	static void Init(Handle<Object> target) {
		//Class
		Local<FunctionTemplate> ctor = Nan::New<FunctionTemplate>(child_class::New);
		constructor.Reset(ctor);
		ctor->InstanceTemplate()->SetInternalFieldCount(1);
		ctor->SetClassName(Nan::New("child_class").ToLocalChecked());
		
		ctor->Inherit(Nan::New( base_class::constructor));

		Nan::SetMethod(ctor, "InstanceOf", InstanceOf);
		

		target->Set(Nan::New("child_class").ToLocalChecked(), ctor->GetFunction());
	}

	

	
};

Nan::Persistent<FunctionTemplate> child_class::constructor;

void init(Handle<Object> target) {
	Nan::SetMethod(target, "test", test);
	base_class::Init(target);
	child_class::Init(target);
}

NODE_MODULE(hello, init);