#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/gordonlin/robot/src/rosserial/rosserial_vex_v5"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/gordonlin/robot/install/lib/python2.7/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/gordonlin/robot/install/lib/python2.7/dist-packages:/home/gordonlin/robot/build/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/gordonlin/robot/build" \
    "/usr/bin/python2" \
    "/home/gordonlin/robot/src/rosserial/rosserial_vex_v5/setup.py" \
     \
    build --build-base "/home/gordonlin/robot/build/rosserial/rosserial_vex_v5" \
    install \
    --root="${DESTDIR-/}" \
    --install-layout=deb --prefix="/home/gordonlin/robot/install" --install-scripts="/home/gordonlin/robot/install/bin"
