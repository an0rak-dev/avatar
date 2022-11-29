# Avatar


## How to get the OpenXR related files (includes + Loader) ?

1. Clone the following repo somewhere : https://github.com/KhronosGroup/OpenXR-SDK
2. Copy the `include/openxr` folder inside `includes/thirdparties/openxr`
3. Download the latest `.nupkg` release in the same repo
4. Rename the `.nupkg` in `.zip` and unzip it
5. Copy the content of `native/<YOUR_ARCH>/release/lib` inside `lib/statics`
6. Copy the content of `native/<YOUR_ARCH>/release/bin` inside `lib/dynaics`