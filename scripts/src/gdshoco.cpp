#include "gdshoco.h"
#include "shoco.h"

using namespace godot;

PoolByteArray Shoco::compress(String s){
	char* in = s.alloc_c_string();
	int size = s.length();
	PoolByteArray out;
	out.resize(size);
	while(true){
		auto write = out.write();
		int compress_size = shoco_compress(in, 0, (char*)write.ptr(), size);
		if(compress_size < size){
			return out;
		}else{
			size *= 2;
			out.resize(size);
		}
	}
}

String Shoco::decompress(PoolByteArray s){
	int size = s.size() * 2 + 1;
	char* out = new char[size];
	shoco_decompress((char*)s.read().ptr(), s.size(), out, size);
	String ret = out;
	delete[] out;
	return ret;
}

void Shoco::_register_methods(){
	register_method("compress", &compress);
	register_method("decompress", &decompress);
}
