/*************************************************************************************************/
/****************************************WIDGET INTERFACE********************************/
#ifndef i_widget_h
#define i_widget_h


class IWidget
{
    public:
        virtual ~IWidget() {}
        virtual void Draw() = 0;
};

#endif
