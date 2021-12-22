icofoam extended solvers:
-------------------------
(1) forcedCovectionIcoFoam
<pre>
Forced Convection Incompressible Laminar Flows
</pre>

(2) buoyantIcoFoam-v1
<pre>
Natural Incompressible Laminar Flow with Boussinesq approximation (First Version)
</pre>

(3) vtBuoyantIcoFoam-v1 
<pre>
Time Adjustable Natural Incompressible Laminar Flow with Boussinesq approximation (First Version)
set adjustTimeStep yes; maxCo 1.0; maxDeltaT 0.5; writeControl adjustableRunTime;
NOTE: writeInterval is actually the run-time to write, e.g. 100 means OF writes at Time = 100.
</pre>
