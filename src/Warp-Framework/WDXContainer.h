// � 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_DX_CONTAINER_H_
#define _W_DX_CONTAINER_H_

#include "WDX.h"

#ifdef _WDX_
class WDXContainer
{
public:
	static void Factory(ID2D1Factory* factory) { WDXContainer::DX_Factory = factory; }
	static const ID2D1Factory* Factory(void) { return WDXContainer::DX_Factory; }

	static void RenderTarget(ID2D1HwndRenderTarget* rt) { WDXContainer::DX_RT = rt; }
	static const ID2D1HwndRenderTarget* RenderTarget(void) { return WDXContainer::DX_RT; }

	static void ClientArea(RECT rect) { WDXContainer::DX_cRect = rect; }
	static const RECT ClientArea(void) { return WDXContainer::DX_cRect; }

	static void WriteFactory(IDWriteFactory* factory) { WDXContainer::DX_WFactory = factory; }
	static const IDWriteFactory* WriteFactory(void) { return WDXContainer::DX_WFactory; }

	static void TextFormat(IDWriteTextFormat* tf) { WDXContainer::DX_TextFormat = tf; }
	static const IDWriteTextFormat* TextFormat(void) { return WDXContainer::DX_TextFormat; }

private:
	static ID2D1Factory* WDXContainer::DX_Factory;
	static ID2D1HwndRenderTarget* WDXContainer::DX_RT;
	static RECT WDXContainer::DX_cRect;
	static IDWriteFactory* WDXContainer::DX_WFactory;
	static IDWriteTextFormat* WDXContainer::DX_TextFormat;
};

#endif // _WDX_
#endif // !_W_DX_CONTAINER_H_
