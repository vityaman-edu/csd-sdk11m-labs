# Developer Guide

## 1. Set your CubeIDE install path

```sh
export CUBE_IDE_PATH=/home/<username>/STM32Cube
```

## 2. Configure the project

After each source tree changes, you need to update your compilation database.

```sh
sh ci/config.sh 1-gpio
```

## 3. Open project with CubeIDE and VSCode

```sh
code lab/1-gpio/project
```

## 4. Develop a feature

Do coding in the `VSCode` editor and switch to `CubeIDE` to build the project.

## 5. Do not forget to format sources

```sh
sh ci/format.sh 1-gpio fix
```
