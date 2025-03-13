#include "webview.hpp"

namespace ferrite {
	webview_t::webview_t() {
		app = ultralight::App::Create();
		window = ultralight::Window::Create(app->main_monitor(), 800, 400, false, kWindowFlags_Titled | kWindowFlags_Resizable);
		
		overlay = ultralight::Overlay::Create(window, 1, 1, 0, 0);
		OnResize(window.get(), window->width(), window->height());
		
		window->SetTitle("Ferrite");
		overlay->view()->LoadURL("file:///app.html");

		app->set_listener(this);
		window->set_listener(this);
		overlay->view()->set_load_listener(this);
		overlay->view()->set_view_listener(this);
	}

	webview_t::~webview_t() { }

	auto webview_t::run() -> void {
		if (app) {
			app->Run();
		}
	}

	auto webview_t::OnResize(ultralight::Window* window, uint32_t width, uint32_t height) -> void {
		overlay->Resize(width, height);
	}
}