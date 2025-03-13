#include "entry-point.hpp"

auto WinMain(HINSTANCE, HINSTANCE, PSTR, int) -> int __stdcall {
	std::thread([&]() {
		auto webview = ferrite::webview_t();
		webview.run();
		}).detach();

	std::thread([&]() {
		while (true) {
			// ...

			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
		}).detach();

	while (true) {
		// ...

		std::this_thread::sleep_for(std::chrono::seconds(1));
	}

	return EXIT_SUCCESS;
}