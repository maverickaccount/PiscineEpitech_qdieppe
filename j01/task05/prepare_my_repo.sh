#!/bin/bash
blih -u quentin.dieppe@epitech.eu repository create $1
blih -u quentin.dieppe@epitech.eu repository setacl $1 ramassage-tek r
echo "ramassage-tek:r"
