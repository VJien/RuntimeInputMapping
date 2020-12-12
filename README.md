



>  This is a plugin about modify Input key at runtime, this version has two demos to modify input keys on the PC, and one demo for VR

## Instructions



### PC

#### TypeA

You need use BP `UW_RIM_Main` to  `CreateWidget` ,  like Map `Demo_PC_TypeA` create it in `RIM_PlayerController`

Then an interface similar to the following will appeared.

![image-20201212114227270](https://img.supervj.top//img/image-20201212114227270.png)



This mode only reads the keyboard and mouse buttons by default

If you want to change it , open `UW_RIM_Main`, change the Map Value `DefaultKeyTypes`

![image-20201212114648400](https://img.supervj.top//img/image-20201212114648400.png)



There are two Types in TypeA, `SingleKey` or `MultiKey`

- SingleKey

If your project only needs one button per action, then this mode is more appropriate.

This type will only read the first button that meets the requirements of each action to provide settings, and it will not take effect for other buttons.

Then you can click any button with the left mouse button (if it is a mouse, you need to hover over this button), and then the following picture will appear, and then press any button to modify the project input settings in real time.

![录制_2020_12_12_12_17_58_489](https://img.supervj.top//img/%E5%BD%95%E5%88%B6_2020_12_12_12_17_58_489.gif)



- MultiKey

Similar to the former, but allows multiple buttons for the same action.

But this adds two additional types of buttons, action can add new button mapping, and the button mapping has a delete button.

![录制_2020_12_12_12_21_28_0](https://img.supervj.top//img/%E5%BD%95%E5%88%B6_2020_12_12_12_21_28_0.gif)







#### TypeB

![image-20201212122513308](https://img.supervj.top//img/image-20201212122513308.png)

![image-20201212122528465](https://img.supervj.top//img/image-20201212122528465.png)



`TypeB` is another setting method, this method can select all the keys of this type in the following other methods

You need use BP `UW_RIM_EX_Main` to  `CreateWidget` ,  like Map `Demo_PC_TypeB` create it in `RIM_PlayerController`

There are 4 types of buttons set by default, if there is no such type of button, then it will display empty, of course you can modify this empty value immediately
Here you can manually set extended keys such as `Alt`

![录制_2020_12_12_12_31_38_205](https://img.supervj.top//img/%E5%BD%95%E5%88%B6_2020_12_12_12_31_38_205.gif)





### VR

You can refer to the map `Demo_VR`, you need to place a class `VR_DisplayBoard` in the scene, this class is a `3D Widget` class, which is interactive in VR
Here is a demonstration with HTC VIVE, here is a special point, because most of the VR buttons cannot be obtained in the blueprint, and the button input cannot be detected by default.
So I suggest that we manually set something similar to `Vive(R)Trigger` into our input configuration by default, so that we can use VR to set the VR buttons through our `3D Widget`

![vr](https://github.com/VJien/img/blob/master/img/%E5%BD%95%E5%88%B6_2020_12_12_12_39_31_879-1607750372074.gif?raw=true)