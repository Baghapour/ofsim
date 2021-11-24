Info<< "Reading transportProperties\n" << endl;

//=== Required Fluid Properties

IOdictionary transportProperties
(
    IOobject
    (
        "transportProperties",
        runTime.constant(),
        mesh,
        IOobject::MUST_READ_IF_MODIFIED,
        IOobject::NO_WRITE
    )
);

dimensionedScalar nu // kinematic viscosity nu = mu/rho
(
    "nu",
    dimViscosity,
    transportProperties.lookup("nu")
);

dimensionedScalar DT // thermal diffusivity DT = k/(rho*cp)
(
    "DT",
    transportProperties.lookup("DT")
);

dimensionedVector g // thermal diffusivity DT = k/(rho*cp)
(
    "g",
    transportProperties.lookup("g")
);

dimensionedScalar T0 // Reference temperature in Kelvin
(
    "T0",
    transportProperties.lookup("T0")
);

dimensionedScalar beta // thermal expansion [beta] = [1/T]
(
    "beta",
    transportProperties.lookup("beta")
);

//=== Pressure Field

Info<< "Reading field p\n" << endl;
volScalarField p
(
    IOobject
    (
        "p",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

//=== Velocity Field

Info<< "Reading field U\n" << endl;
volVectorField U
(
    IOobject
    (
        "U",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

//=== Temperature Field

Info<< "Reading field T\n" << endl;
volScalarField T
(
    IOobject
    (
        "T",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

#include "createPhi.H"

label pRefCell = 0;
scalar pRefValue = 0.0;
setRefCell(p, mesh.solutionDict().subDict("PISO"), pRefCell, pRefValue);
mesh.setFluxRequired(p.name());
