#ifndef RENDER_H
#define RENDER_H



class Render {
    public:
        void clear_screen();
        void draw_unit(auto u);
        void draw_screen();
        void refresh_screen();
        void render_engine();
};

#endif