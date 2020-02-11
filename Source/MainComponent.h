/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class MainComponent   : public Component, public Timer
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

    void mouseUp(const MouseEvent& e) override;
    void timerCallback() override;
    
    void refreshMenu(bool altDown);
    
private:
    PopupMenu menu;
    PopupMenu menuAlt;
    bool menuVisible = false;
    bool altVisible = false;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
