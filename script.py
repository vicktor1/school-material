import FreeCAD as App

doc = App.activeDocument()

cylinder = doc.addObject("Part::Cylinder", "myCylinder")
cylinder.Radius = 10
cylinder.Height = 50
# cylinder.Placement = App.Placement(App.Vector(5, 10, 15), App.Rotation(75, 60, 30))
cylinder.Placement = App.Placement(App.Vector(0, 0, 0), App.Rotation(0, 0, 0))
doc.recompute()

