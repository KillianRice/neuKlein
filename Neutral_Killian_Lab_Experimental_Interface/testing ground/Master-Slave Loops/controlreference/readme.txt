You can pass access to front panel control or indicator values to subVIs by using explicitly linked control references.  

In the main VI, there is a Control Reference Constant for the Waveform Chart Indicator and the Boolean Strop Control.  These references are wired to the subVI.

The subVI has two Control Refnum Controls.  One corresponding to the Waveform Chart and one to the Boolean.  Looking at the subVI block diagram, we can see what is being done with the control and indicator from the main VI.  The Waveform Chart Refnum is fed to a Property Node that turns on autoscaling for the chart.  This refnum is then passed inside the while loop where it is used to write a value to the chart in the front panel of the main VI.  Meanwhile, the Boolean refnum is being used to read the current value of the Boolean control in the main VI's front panel to determnie when the user selected the stop button.

This example illustrates how to read and write values from a subVI to controls and indicators in a main VI.  A similar example that would be useful involves doing data acquistion in a subVI, displaying the data in the main VI, and terminating the data acquisition being done in the subVI from the main VI.

More more information on creating Control References, see the Concept Document on NI Developer Zone titiled "Control References:  Overview".