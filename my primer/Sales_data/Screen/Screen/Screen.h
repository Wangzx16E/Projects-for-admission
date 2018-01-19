//
//  Screen.h
//  Screen

#ifndef Screen_h
#define Screen_h

#include <string>
#include <vector>
#include <iostream>

class Screen;

class Window_mgr{
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    inline void clear(ScreenIndex);
private:
    std::vector<Screen> screens;
};

class Screen {
    friend void Window_mgr::clear(ScreenIndex);
public:
    typedef std::string::size_type pos;
    
    Screen() = default;
    Screen(pos ht, pos wd): height(ht), width(wd), contents(ht * wd,' ') { }
    Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd, c) { }
    
    char get() const  {return contents[cursor]; }
    inline char get(pos r, pos c) const { return contents[r * width + c]; }
    
    inline Screen &move(pos r, pos c);
    inline Screen &set(char);    //set current value
    inline Screen &set(pos, pos, char);    //set value of given location
    
    Screen &display(std::ostream &os) {do_display(os); return *this; }
    const Screen &display(std::ostream &os) const {do_display(os); return *this; }

private:
    void do_display(std::ostream &os) const {os << contents;}
    
    
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};

inline void Window_mgr::clear(ScreenIndex i)
{
    if (i >= screens.size()) return;
    Screen &s = screens[i];
    s.contents = std::string(s.height * s.width, ' ');
}

inline Screen &Screen::move(pos r, pos c)
{
    cursor = r * width + c ;
    return *this;
}
inline Screen &Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}
inline Screen &Screen::set(pos r, pos col, char ch)
{
    contents[r * width + col] = ch;
    return *this;
}



#endif /* Screen_h */
