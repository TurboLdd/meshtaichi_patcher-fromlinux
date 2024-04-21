python3 setup.py clean --all
rm -rf ./build
rm -rf ./dist
python3 setup.py build
python3 setup.py install --user