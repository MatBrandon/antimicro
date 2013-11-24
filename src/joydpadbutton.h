#ifndef JOYDPADBUTTON_H
#define JOYDPADBUTTON_H

#include "joybutton.h"

class JoyDPad;

class JoyDPadButton : public JoyButton
{
    Q_OBJECT
public:
    JoyDPadButton(int direction, int originset, JoyDPad* dpad, QObject *parent=0);

    QString getDirectionName();
    virtual int getRealJoyNumber();
    virtual QString getPartialName(bool forceFullFormat=false);
    virtual QString getXmlName();
    JoyDPad *getDPad();

    virtual void setChangeSetCondition(SetChangeCondition condition, bool passive=false);

    enum JoyDPadDirections {
        DpadCentered = 0, DpadUp = 1, DpadRight = 2,
        DpadDown = 4, DpadLeft = 8, DpadRightUp = 3,
        DpadRightDown = 6, DpadLeftUp = 9, DpadLeftDown = 12
    };
    static const QString xmlName;

protected:
    int direction;
    JoyDPad *dpad;

signals:
    void setAssignmentChanged(int current_button, int dpad_index, int associated_set, int mode);

public slots:
    virtual void reset();
    virtual void reset(int index);
};

#endif // JOYDPADBUTTON_H
