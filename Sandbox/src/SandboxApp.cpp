#include <WEngined.h>

class Sandbox : public WEngined::Application {

public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

WEngined::Application* WEngined::CreateApplication() {
	return new Sandbox();
}