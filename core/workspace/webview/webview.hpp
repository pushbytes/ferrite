#pragma once

#include <windows.h>
#include <string>
#include <thread>
#include <memory>
#include <mutex>

#include <AppCore/AppCore.h>
#include <AppCore/App.h>
#include <AppCore/Window.h>
#include <AppCore/Overlay.h>
#include <AppCore/CAPI.h>

namespace ferrite {
	class webview_t : public ultralight::AppListener, public ultralight::WindowListener, public ultralight::LoadListener, public ultralight::ViewListener {
	public:
		webview_t();
		virtual ~webview_t();

		virtual auto run() -> void;

		// events
		virtual auto OnResize(ultralight::Window* window, uint32_t width, uint32_t height) -> void override;
	private:
		ultralight::RefPtr<ultralight::App> app;
		ultralight::RefPtr<ultralight::Window> window;
		ultralight::RefPtr<ultralight::Overlay> overlay;
	};
}
