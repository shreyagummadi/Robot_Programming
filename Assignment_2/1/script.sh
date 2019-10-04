
#!/bin/bash
echo "test script to execute DoxygenExample"


./../build-Debug/bin/DoxygenExample 
echo $?

if ($? == 0); then
 echo main successful
fi
