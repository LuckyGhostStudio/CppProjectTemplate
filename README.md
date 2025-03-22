# C++ & EasyX 项目模板

一个用于快速构建 EasyX 项目的模板，适用于使用 Core/App 项目架构的 C++ 项目。，其中包含两个项目：Core 和 App。[Premake](https://github.com/premake/premake-core)用于生成项目文件。

Core 会构建为静态库，是该项目的通用代码库。App 会构建为可执行文件，它会链接 Core 静态库。

`Scripts/`目录包含 `Windows` 的构建脚本，`Vendor/`目录包含 Premake 二进制文件（当前版本为`5.0-beta2`）。

## 构建指南
1. 克隆该存储库的 `easyx` 分支 `git clone -b easyx --single-branch https://github.com/LuckyGhostStudio/CppProjectTemplate.git` 或使用 GitHub 上的 "Use this template" 按钮根据此模板快速设置自己的存储库。
2. 打开 `Scripts/` 目录，运行 `Setup-Windows.bat` 脚本来生成项目文件。也可以通过更改脚本来更改生成的项目类型，当前项目设置为 Visual Studio 2022。
3. 三个 Premake 构建文件是 `Build.lua`、`Core/Build-Core.lua` 和 `App/Build-App.lua`。可以编辑这些文件来定制构建配置，编辑项目名称和工作区/解决方案等。

## 模板内容
- `Core/Source` 中提供了一个 EasyX Demo 代码示例，在 `App/Source` 中调用进行测试。
- `.gitignore` 用于忽略项目文件和二进制文件。
- Windows 平台的 Premake 二进制文件 (`v5.0-beta2`)

## 许可证
- 此存储库的 UNLICENSE (`UNLICENSE.txt` 文件)
- Premake 根据 BSD 3-Clause 获得许可 (`LICENSE.txt` 文件)