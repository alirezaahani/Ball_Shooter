#include "LTexture.h"

LTexture::LTexture(uint8_t ColorKeyR, uint8_t ColorKeyG, uint8_t ColorKeyB, SDL_Renderer* renderer) {
    mTexture = nullptr;
    mWidth = 0;
    mHeight = 0;

    // Color keys for transparency
    mColorKeyR = ColorKeyR;
    mColorKeyG = ColorKeyG;
    mColorKeyB = ColorKeyB;

    // Targeted renderer
    mRenderer = renderer;
}

LTexture::~LTexture() {
    free();
}

bool LTexture::loadFromFile(std::string path) {

    free();

    // Final texture
    SDL_Texture* newTexture = nullptr;

    // Load picture to surface
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if(loadedSurface == nullptr) {
        std::cout << "ERR::SDL::LOADBMP " << path.c_str() << " " << IMG_GetError() << std::endl;
        return false;
    }

    // Color key for transparency
    SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, mColorKeyR, mColorKeyG, mColorKeyB));

    // Convert surface to texture
    newTexture = SDL_CreateTextureFromSurface(mRenderer, loadedSurface);
    if(newTexture == nullptr) {
        std::cout << "ERR::SDL::LOADTEX " << path.c_str() << " " << SDL_GetError() << std::endl;
        return false;
    }

    // Set height and width
    mHeight = loadedSurface->h;
    mWidth = loadedSurface->w;

    // Remove unused surface
    SDL_FreeSurface(loadedSurface);

    // Change member texture
    mTexture = newTexture;

    return true;
}

bool LTexture::loadFromFont(std::string textureText, SDL_Color textColor, TTF_Font* font) {
    // Remove existing texture
    free();

    // Create font surface
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, textureText.c_str(), textColor);
    if(textSurface == nullptr) {
        std::cout << "ERR::SDL::LOADFONT::SURFACE " << TTF_GetError() << std::endl;
        return false;
    }

    // Convert font surface to texture for rendering
    mTexture = SDL_CreateTextureFromSurface(mRenderer, textSurface);
    if(mTexture == nullptr) {
        std::cout << "ERR::SDL::LOADFONT::TEX " << TTF_GetError() << std::endl;
        return false;
    }

    // Get width and height for text texture
    mWidth = textSurface->w;
    mHeight = textSurface->h;

    // Free unused surface
    SDL_FreeSurface(textSurface);

    return true;
}

void LTexture::free() {
    // If the texture isn't cleared or invalid
    if(mTexture != nullptr) {
        // Destroy the textures and make it invalid
        SDL_DestroyTexture(mTexture);
        mTexture = nullptr;
        mWidth = 0;

        mHeight = 0;
    }
}

void LTexture::render(int x, int y, SDL_Rect* clip, int w, int h, double angle, SDL_Point* center, SDL_RendererFlip flip) {
    // Set rendering space and render to screen
    SDL_Rect renderQuad = { x, y, mWidth, mHeight };

    // If clip specified
    if(clip != nullptr) {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;

        // Scaling
        if(w != 0 && h != 0) {
            renderQuad.w = w;
            renderQuad.h = h;
            mWidth = w;
            mHeight = h;
        }
    }

    SDL_RenderCopyEx(mRenderer, mTexture, clip, &renderQuad, angle, center, flip);
}

void LTexture::setColor(uint8_t R, uint8_t G, uint8_t B) {
    // Modulate texture
    SDL_SetTextureColorMod(mTexture, R, G, B);
}

void LTexture::setBlendMode(SDL_BlendMode blending) {
    // Set blending function
    SDL_SetTextureBlendMode(mTexture, blending);
}

void LTexture::setAlpha(uint8_t alpha) {
    // Modulate texture alpha
    SDL_SetTextureAlphaMod(mTexture, alpha);
}

int LTexture::getWidth() {
    return mWidth;
}

int LTexture::getHeight() {
    return mHeight;
}
