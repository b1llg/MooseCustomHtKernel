[Mesh]
    type = GeneratedMesh # Can generate simple lines, rectangles and rectangular prisms
    dim  = 2 # Dimension of the mesh
    nx   = 8 # Number of elements in the x direction
    ny   = 8 # Number of elements in the y direction
    xmax = 1.0 # m - width of box
    ymax = 1.0 # m - height of box
[]
[Variables]
    [temperature]
      order = FIRST
      family = LAGRANGE
    []
[]
[Kernels]
    [conduction]
      type = ADHeatTransferConduction # Zero-gravity, divergence-free form of Darcy's law
      variable = temperature # Operate on the "pressure" variable from above
    []
[BCs]
    [right]
      type = ADDirichletBC # Simple u=value BC
      variable = pressure # Variable to be set
      boundary = left # Name of a sideset in the mesh
      value = 500 # degK
    []
    [left]
      type = ADDirichletBC
      variable = pressure
      boundary = right
      value = 273 # degK
    []
[]
[Executioner]
    type = Steady # Steady state problem
    solve_type = NEWTON # Perform a Newton solve
  
    # Set PETSc parameters to optimize solver efficiency
    petsc_options_iname = '-pc_type -pc_hypre_type' # PETSc option pairs with values below
    petsc_options_value = ' hypre    boomeramg'
[]
[Outputs]
    exodus = true # Output Exodus format
    perf_graph = true
[]