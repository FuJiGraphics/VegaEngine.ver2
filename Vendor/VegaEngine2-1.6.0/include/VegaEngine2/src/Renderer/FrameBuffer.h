#pragma once

namespace fz {

	struct FramebufferSpec
	{
		int	Width;
		int	Height;
		int	MultisampleLevel = 1;
		bool SwapChainTarget = false;
	};

	class Framebuffer
	{
	public:
		static Shared<Framebuffer> Create(const FramebufferSpec& specification);

		virtual FramebufferSpec GetInfo() const = 0;
		virtual sf::RenderTexture& GetBuffer() = 0;
		virtual void Clear() = 0;
	};

} // namespace fz