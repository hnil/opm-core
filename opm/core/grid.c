/*
  Copyright 2012 SINTEF ICT, Applied Mathematics.

  This file is part of the Open Porous Media project (OPM).

  OPM is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  OPM is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with OPM.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <opm/core/grid.h>
#include <stdlib.h>

void destroy_grid(struct UnstructuredGrid *g)
{
    if (g!=NULL)
    {
        free(g->face_nodes);
        free(g->face_nodepos);
        free(g->face_cells);
        free(g->cell_facepos);
        free(g->cell_faces);

        free(g->node_coordinates);
        free(g->face_centroids);
        free(g->face_areas);
        free(g->face_normals);
        free(g->cell_centroids);
        free(g->cell_volumes);

        free(g->global_cell);
        free(g->cell_facetag);
    }

    free(g);
}


struct UnstructuredGrid *
create_grid_empty(void)
{
    struct UnstructuredGrid *G, g = { 0 };

    G = malloc(1 * sizeof *G);

    if (G != NULL) {
        *G = g;
    }

    return G;
}
