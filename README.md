# C++ ��Ŀģ��

һ�����ڿ��ٹ�����Ŀ��ģ�壬������ʹ�� Core/App ��Ŀ�ܹ��� C++ ��Ŀ�����а���������Ŀ��Core �� App��[Premake](https://github.com/premake/premake-core)����������Ŀ�ļ���

Core �ṹ��Ϊ��̬�⣬�Ǹ���Ŀ��ͨ�ô���⡣App �ṹ��Ϊ��ִ���ļ����������� Core ��̬�⡣

`Scripts/`Ŀ¼���� `Windows` �� `Linux` �Ĺ����ű���`Vendor/`Ŀ¼���� Premake �������ļ�����ǰ�汾Ϊ`5.0-beta2`����

ע������Ŀģ���޸��� [TheCherno](https://github.com/TheCherno/ProjectTemplate)��

## ��֧˵��
1. main - ����֧�������з�֧�ϲ� (����)
2. empty - �շ�֧��һ���յ� C++ ��Ŀģ��
3. easyx - EasyX ��֧��һ�������� EasyX �� C++ ��Ŀģ��

## ����ָ��
1. ��¡�ô洢��� `empty` ��֧ `git clone -b empty --single-branch https://github.com/LuckyGhostStudio/CppProjectTemplate` ��ʹ�� GitHub �ϵ� "Use this template" ��ť���ݴ�ģ����������Լ��Ĵ洢�⡣
2. �� `Scripts/` Ŀ¼�����ж�Ӧƽ̨�� `Setup-XXX` �ű���������Ŀ�ļ���Ҳ����ͨ�����Ľű����������ɵ���Ŀ���ͣ���ǰ Windows ��Ŀ����Ϊ Visual Studio 2022��Linux ��Ŀ����Ϊ gmake2��
3. ���� Premake �����ļ��� `Build.lua`��`Core/Build-Core.lua` �� `App/Build-App.lua`�����Ա༭��Щ�ļ������ƹ������ã��༭��Ŀ���ƺ͹�����/��������ȡ�

Ŀǰû���ṩ MacOS ƽ̨�Ĺ����ű������Ը��� Linux �ű���������Ӧ������

## ģ������
- `Core/Source` ���ṩ��һ���������ʾ������ `App/Source` �е��ý��в��ԡ�
- `.gitignore` ���ں�����Ŀ�ļ��Ͷ������ļ���
- Windows/MacOS/Linux ƽ̨�� Premake �������ļ� (`v5.0-beta2`)

## ���֤
- �˴洢��� UNLICENSE (`UNLICENSE.txt` �ļ�)
- Premake ���� BSD 3-Clause ������ (`LICENSE.txt` �ļ�)