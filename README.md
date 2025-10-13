# LootLocker Unreal Admin SDK

## About

This is an unofficial Admin SDK Unreal Plugin for LootLocker. We at Fast Travel Games use this to automate some of the config for our LootLocker backend.

LootLocker is a game backend-as-a-service that unlocks cross-platform systems so you can build, ship, and run your best games.

Full documentation is available [here](https://docs.lootlocker.com/)

## Installation

For a more detailed guide on installation, please see LootLockers [User Documentation](https://docs.lootlocker.com/getting-started/unreal-tutorials/getting-started-with-unreal). This Admin SDK is very similar to the Game and Server SDK.

1. Clone this repo
2. Copy the LootLockerAdminSDK folder.
3. Paste the LootLockerAdminSDK folder into the plugins folder created in the root of your project (create if it doesn't exist)
4. Right-click on the "Unreal Engine Project Launch" file in the root of your project and click on "Generate Visual Studio Project Files"
5. Open the .sln file of your project
6. Open your project's Build.cs file
7. Add `LootLockerAdminSDK` to the PublicDependencyModuleNames list

    Example:
    ```cpp
    PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "LootLockerAdminSDK" });
    ```
8. Add `{"HTTP", "Json", "JsonUtilities"}` to the PrivateDependencyModuleNames list

    Example:
    ```cpp
    PrivateDependencyModuleNames.AddRange(new string[] { "HTTP", "Json", "JsonUtilities" });
    ```

## Configuration

1. Navigate to Edit/Project Settings in the editor, Scroll down on the left panel until the plugins sections of the project settings, Click on LootLockerAdminSDK
2. Modify the Game ID value. This is the number you find in the path for the game in the LootLocker console. You should also already have an account from [https://console.lootlocker.com/login](https://console.lootlocker.com/login "https://console.lootlocker.com/login") so check there.

## Usage

Typically you will need to call `StartSession` before any other function will work.

## Support

This is a plugin used by Fast Travel Games to help with config our backend(s). This can be used as is but we provide no support for the functionality
