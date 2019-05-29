#pragma once

#include <Godot.hpp>

namespace godot{

class Shoco : public Reference{
	GODOT_CLASS(Shoco, Reference);
public:
	void _init(){}

	PoolByteArray compress(String s);
	String decompress(PoolByteArray s);

	static void _register_methods();
};

}