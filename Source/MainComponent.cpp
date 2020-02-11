/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    menu.addItem(1, "Menu 1");
    menu.addItem(2, "Menu 2");
    menu.addItem(3, "Menu 3");
    
    menuAlt.addItem(1, "Menu 1 Alt");
    menuAlt.addItem(2, "Menu 2 Alt");
    menuAlt.addItem(3, "Menu 3 Alt");
    
    
    setSize (600, 400);
}

MainComponent::~MainComponent()
{
}

void MainComponent::timerCallback()
{
    auto mods =  ModifierKeys::getCurrentModifiers();

    refreshMenu( mods.isAltDown() );
}

void MainComponent::mouseUp(const MouseEvent& e)
{
    startTimerHz(30);
}

void MainComponent::refreshMenu(bool altDown)
{
    if (altVisible != altDown || !menuVisible)
    {
        altVisible = altDown;
        PopupMenu::dismissAllActiveMenus();
        
        auto& m = altDown ? menuAlt : menu;
        PopupMenu::Options o;
        o = o.withTargetScreenArea ({100, 100, 200, 100});
        
        menuVisible = true;
        m.showMenuAsync(o, [&](int i)
        {
            if (i > 0)
            {
                stopTimer();
                menuVisible = false;
            }

        });
    }
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

}

void MainComponent::resized()
{

}
