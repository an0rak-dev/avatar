# Avatar

**IMPORTANT** : This project is still a work in Progress. More features will come later.

## How to build 

### Windows

This project uses Visual Studio Code mainly, but you can still use directly VisualStudio.

1. Install Visual Studio (at last the community edition) on your computer
2. Install Visual Studio Code
3. Install the C/C++ extension on VSCode by Microsoft
4. Open a new instance of VSCode using the VS Developer Command Prompt (`code <dir-to-your-project-locally>`)
5. Smash that `F5` button to build & run the project.

## How to get the OpenXR related files (includes + Loader) ?

1. Clone the following repo somewhere : https://github.com/KhronosGroup/OpenXR-SDK
2. Copy the `include/openxr` folder inside `includes/thirdparties/openxr`
3. Download the latest `.nupkg` release in the same repo
4. Rename the `.nupkg` in `.zip` and unzip it
5. Copy the content of `native/<YOUR_ARCH>/release/lib` inside `lib/statics`
6. Copy the content of `native/<YOUR_ARCH>/release/bin` inside `lib/dynaics`