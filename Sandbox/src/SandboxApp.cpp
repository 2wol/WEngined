#include <WEngined.h>

class ExampleLayer : public WEngined::Layer {
public:
	ExampleLayer() : Layer("Example") {}

	void OnUpdate() override {
		//HZ_INFO("ExampleLayer: Update");
	}

	void OnEvent(WEngined::Event& event) override {
		//HZ_TRACE("{0}", event.ToString());
	}
};

class Sandbox : public WEngined::Application {

public:
	Sandbox() {
		PushLayer(new ExampleLayer());
		PushOverlay(new WEngined::ImGuiLayer());
	}

	~Sandbox() {

	}
};

WEngined::Application* WEngined::CreateApplication() {
	return new Sandbox();
}