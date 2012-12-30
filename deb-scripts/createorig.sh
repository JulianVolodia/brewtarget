#!/bin/bash

SVNDIR="trunk"
NAME="brewtarget"
VERSION="2.0.0"
TARDIR="$NAME-$VERSION"
TARFILE="${NAME}_${VERSION}.orig.tar"

if [ -n "$1" ]
then
   SVNDIR="$1"
fi

# Copy SVNDIR to TARDIR
cp -r ${SVNDIR} ${TARDIR}

# Clean the source dir of extraneous files/dirs
cd ${TARDIR}
rm -rf $(svn status | grep '?' | sed 's/[?]\s*//') # Remove files not under svn control.
cd ..
rm -rf $(find ${TARDIR} | grep '.svn') # Remove svn files.
rm -rf $(find ${TARDIR} | grep -e '.*[~]') # Remove backup files.

# Move debian/ outside
mv "${TARDIR}/debian" .

# Create tar file
tar -cf ${TARFILE} ${TARDIR}

# Zip tar file
gzip --best ${TARFILE}

# Move debian/ back inside
mv debian ${TARDIR}

