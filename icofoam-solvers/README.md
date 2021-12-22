icofoam extended solvers:
-------------------------
(1) forcedCovectionIcoFoam: 
<pre>
Forced Convection Incompressible Laminar Flows
</pre>

(2) buoyantIcoFoam-v1: Natural Incompressible Laminar Flow with Boussinesq approximation (First Version)

(3) vtBuoyantIcoFoam-v1: Time Adjustable Natural Incompressible Laminar Flow with Boussinesq approximation (First Version) <br>
                         set adjustTimeStep yes; maxCo 1.0; maxDeltaT 0.5; writeControl adjustableRunTime; <br>
                         NOTE: writeInterval is actually the run-time to write, e.g. 100 means OF writes at Time = 100.
