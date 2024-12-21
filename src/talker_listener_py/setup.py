from setuptools import find_packages, setup

package_name = 'talker_listener_py'

setup(
    name=package_name,
    version='0.0.1',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='edreate',
    maintainer_email='edreate.dev@gmail.com',
    description='Basic talker listener node in python.',
    license='MIT',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'talker = talker_listener_py.talker:main',
            'listener = talker_listener_py.listener:main'
        ],
    },
)
