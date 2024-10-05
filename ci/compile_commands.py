from argparse import ArgumentParser
from pathlib import Path
import json


parser = ArgumentParser(
    prog='CompileCommandsGenerator',
    description=(
        'Generates compilation database of your STM32Cube project. '
        'Produces compile_commands.json file for Clang tooling.'
    ),
)
parser.add_argument(
    '-d', '--project_dir', 
    required=True, help='Path to STM32Cube project'
)
parser.add_argument(
    '-i', '--install_dir', 
    required=True, help='Path to STM32CubeIDE installation directory'
)


if __name__ == '__main__':
    args = parser.parse_args()
    project_dir = Path(args.project_dir).absolute()
    install_dir = Path(args.install_dir).absolute()

    compiler = 'clang++'

    plugin_dir = Path(
        install_dir, 'stm32cubeide_1.9.0', 'plugins', 
        'com.st.stm32cube.ide.mcu.externaltools.gnu-tools-for-stm32.10.3-2021.10.linux64_1.0.0.202111181127',
    )
    includes = (
        Path('Core', 'Inc'),
        Path('Drivers', 'CMSIS', 'Device', 'ST', 'STM32F4xx', 'Include'),
        Path('Drivers', 'CMSIS', 'Include'),
        Path('Drivers', 'STM32F4xx_HAL_Driver', 'Inc'),
        Path('Drivers', 'STM32F4xx_HAL_Driver', 'Inc', 'Legacy'),
        Path(plugin_dir, 'tools', 'arm-none-eabi', 'include'),
        Path(plugin_dir, 'tools', 'arm-none-eabi', 'include', 'c++', '10.3.1'),
    )

    cxx_flags = ' '.join(f'-I{_}' for _ in includes)

    sources = Path(project_dir, 'Core', 'Src').rglob('*.cpp')

    compile_commands: list[dict[str, str]] = []
    for source in sources:
        compile_commands.append({
            'command': f'{compiler} -c -o {source}.o {cxx_flags} {source}',
            'directory': str(project_dir),
            'file': str(source),
        })

    print(json.dumps(compile_commands, indent=4))
