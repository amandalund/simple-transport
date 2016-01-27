#include "header.h"

// Read in parameters from file
void parse_params(char *filename, Parameters *params)
{
  char line[256], *s;
  FILE *fp = fopen(filename, "r");

  while((s = fgets(line, sizeof(line), fp)) != NULL){

    if(line[0] == '#') continue;
    if(line[0] == '\n') continue;
    s = strtok(line, "=");
    if(s == NULL) continue;

    // Number of particles
    else if(strcmp(s, "particles") == 0){
      long long n_particles = atoll(strtok(NULL, "=\n"));
      if(n_particles < 1)
        print_error("Number of particles must be greater than 0");
      params->n_particles = n_particles;
    }

    // Number of batches
    else if(strcmp(s, "batches") == 0){
      params->n_batches = atoi(strtok(NULL, "=\n"));
    }

    // Number of generations
    else if(strcmp(s, "generations") == 0){
      params->n_generations = atoi(strtok(NULL, "=\n"));
    }

    // Number of active batches
    else if(strcmp(s, "active") == 0){
      params->n_active = atoi(strtok(NULL, "=\n"));
    }

    // Number of nuclides in material
    else if(strcmp(s, "nuclides") == 0){
      params->n_nuclides = atoi(strtok(NULL, "=\n"));
    }

    // Whether to tally
    else if(strcmp(s, "tally") == 0){
      s = strtok(NULL, "=\n");
      if(strcasecmp(s, "true") == 0)
        params->tally = TRUE;
      else if(strcasecmp(s, "false") == 0)
        params->tally = FALSE;
      else
        print_error("Invalid option for parameter 'tally': must be 'true' or 'false'");
    }

    // Number of bins in each dimension
    else if(strcmp(s, "bins") == 0){
      params->n_bins = atoi(strtok(NULL, "=\n"));
    }

    // RNG seed
    else if(strcmp(s, "seed") == 0){
      params->seed = atoi(strtok(NULL, "=\n"));
    }

    // Average number of fission neutrons produced
    else if(strcmp(s, "nu") == 0){
      params->nu = atof(strtok(NULL, "=\n"));
    }

    // Fission macro xs
    else if(strcmp(s, "xs_f") == 0){
      params->xs_f = atof(strtok(NULL, "=\n"));
    }

    // Absorption macro xs
    else if(strcmp(s, "xs_a") == 0){
      params->xs_a = atof(strtok(NULL, "=\n"));
    }

    // Scattering macro xs
    else if(strcmp(s, "xs_s") == 0){
      params->xs_s = atof(strtok(NULL, "=\n"));
    }

    // Geometry size in x
    else if(strcmp(s, "x") == 0){
      params->gx = atof(strtok(NULL, "=\n"));
    }

    // Geometry size in y
    else if(strcmp(s, "y") == 0){
      params->gy = atof(strtok(NULL, "=\n"));
    }

    // Boundary conditions
    else if(strcmp(s, "bc") == 0){
      s = strtok(NULL, "=\n");
      if(strcasecmp(s, "vacuum") == 0)
        params->bc = 0;
      else if(strcasecmp(s, "reflective") == 0)
        params->bc = 1;
      else if(strcasecmp(s, "periodic") == 0)
        params->bc = 2;
      else
        print_error("Invalid boundary condition");
    }

    // Whether to load source
    else if(strcmp(s, "load_source") == 0){
      s = strtok(NULL, "=\n");
      if(strcasecmp(s, "true") == 0)
        params->load_source = TRUE;
      else if(strcasecmp(s, "false") == 0)
        params->load_source = FALSE;
      else
        print_error("Invalid option for parameter 'load_source': must be 'true' or 'false'");
    }

    // Whether to save source
    else if(strcmp(s, "save_source") == 0){
      s = strtok(NULL, "=\n");
      if(strcasecmp(s, "true") == 0)
        params->save_source = TRUE;
      else if(strcasecmp(s, "false") == 0)
        params->save_source = FALSE;
      else
        print_error("Invalid option for parameter 'save_source': must be 'true' or 'false'");
    }

    // Whether to output tally
    else if(strcmp(s, "write_tally") == 0){
      s = strtok(NULL, "=\n");
      if(strcasecmp(s, "true") == 0)
        params->write_tally = TRUE;
      else if(strcasecmp(s, "false") == 0)
        params->write_tally = FALSE;
      else
        print_error("Invalid option for parameter 'write_tally': must be 'true' or 'false'");
    }

    // Whether to output shannon entropy
    else if(strcmp(s, "write_entropy") == 0){
      s = strtok(NULL, "=\n");
      if(strcasecmp(s, "true") == 0)
        params->write_entropy = TRUE;
      else if(strcasecmp(s, "false") == 0)
        params->write_entropy = FALSE;
      else
        print_error("Invalid option for parameter 'write_entropy': must be 'true' or 'false'");
    }

    // Whether to output keff
    else if(strcmp(s, "write_keff") == 0){
      s = strtok(NULL, "=\n");
      if(strcasecmp(s, "true") == 0)
        params->write_keff = TRUE;
      else if(strcasecmp(s, "false") == 0)
        params->write_keff = FALSE;
      else
        print_error("Invalid option for parameter 'write_keff': must be 'true' or 'false'");
    }

    // Whether to output particle bank
    else if(strcmp(s, "write_bank") == 0){
      s = strtok(NULL, "=\n");
      if(strcasecmp(s, "true") == 0)
        params->write_bank = TRUE;
      else if(strcasecmp(s, "false") == 0)
        params->write_bank = FALSE;
      else
        print_error("Invalid option for parameter 'write_bank': must be 'true' or 'false'");
    }

    // Whether to output source distribution
    else if(strcmp(s, "write_source") == 0){
      s = strtok(NULL, "=\n");
      if(strcasecmp(s, "true") == 0)
        params->write_source = TRUE;
      else if(strcasecmp(s, "false") == 0)
        params->write_source = FALSE;
      else
        print_error("Invalid option for parameter 'write_source': must be 'true' or 'false'");
    }

    // Path to write tallies to
    else if(strcmp(s, "tally_file") == 0){
      s = strtok(NULL, "=\n");
      params->tally_file = malloc(strlen(s)*sizeof(char)+1);
      strcpy(params->tally_file, s);
    }

    // Path to write shannon entropy to
    else if(strcmp(s, "entropy_file") == 0){
      s = strtok(NULL, "=\n");
      params->entropy_file = malloc(strlen(s)*sizeof(char)+1);
      strcpy(params->entropy_file, s);
    }

    // Path to write keff to
    else if(strcmp(s, "keff_file") == 0){
      s = strtok(NULL, "=\n");
      params->keff_file = malloc(strlen(s)*sizeof(char)+1);
      strcpy(params->keff_file, s);
    }

    // Path to write bank to
    else if(strcmp(s, "bank_file") == 0){
      s = strtok(NULL, "=\n");
      params->bank_file = malloc(strlen(s)*sizeof(char)+1);
      strcpy(params->bank_file, s);
    }

    // Path to write source distribution to
    else if(strcmp(s, "source_file") == 0){
      s = strtok(NULL, "=\n");
      params->source_file = malloc(strlen(s)*sizeof(char)+1);
      strcpy(params->source_file, s);
    }

    // Unknown config file option
    else print_error("Unknown option in config file.");
  }

  fclose(fp);

  return;
}

void read_CLI(int argc, char *argv[], Parameters *params)
{
  int i;
  char *arg;

  // Collect raw input
  for(i=1; i<argc; i++){
    arg = argv[i];

    // Number of particles (-particles)
    if(strcmp(arg, "-particles") == 0){
      if(++i < argc){
        long long n_particles = atoll(argv[i]);
        if(n_particles < 1)
          print_error("Number of particles must be greater than 0");
        params->n_particles = n_particles;
      }
      else print_error("Error reading command line input '-particles'");
    }

    // Number of batches (-batches)
    else if(strcmp(arg, "-batches") == 0){
      if(++i < argc) params->n_batches = atoi(argv[i]);
      else print_error("Error reading command line input '-batches'");
    }

    // Number of active batches (-active)
    else if(strcmp(arg, "-active") == 0){
      if(++i < argc) params->n_active = atoi(argv[i]);
      else print_error("Error reading command line input '-active'");
    }

    // Number of generations (-generations)
    else if(strcmp(arg, "-generations") == 0){
      if(++i < argc) params->n_generations = atoi(argv[i]);
      else print_error("Error reading command line input '-generations'");
    }

    // Boundary conditions (-bc)
    else if(strcmp(arg, "-bc") == 0){
      if(++i < argc){
        if(strcasecmp(argv[i], "vacuum") == 0)
          params->bc = 0;
        else if(strcasecmp(argv[i], "reflective") == 0)
          params->bc = 1;
        else if(strcasecmp(argv[i], "periodic") == 0)
          params->bc = 2;
        else
          print_error("Invalid boundary condition");
      }
      else print_error("Error reading command line input '-bc'");
    }

    // Number of nuclides in material (-nuclides)
    else if(strcmp(arg, "-nuclides") == 0){
      if(++i < argc) params->n_nuclides = atoi(argv[i]);
      else print_error("Error reading command line input '-nuclides'");
    }

    // Whether to tally (-tally)
    else if(strcmp(arg, "-tally") == 0){
      if(++i < argc){
        if(strcasecmp(argv[i], "true") == 0)
          params->tally = TRUE;
        else if(strcasecmp(argv[i], "false") == 0)
          params->tally = FALSE;
        else
          print_error("Invalid option for parameter 'tally': must be 'true' or 'false'");
      }
      else print_error("Error reading command line input '-tally'");
    }

    // Number of bins in each dimension (-bins)
    else if(strcmp(arg, "-bins") == 0){
      if(++i < argc) params->n_bins = atoi(argv[i]);
      else print_error("Error reading command line input '-bins'");
    }

    // RNG seed (-seed)
    else if(strcmp(arg, "-seed") == 0){
      if(++i < argc) params->seed = atoi(argv[i]);
      else print_error("Error reading command line input '-seed'");
    }

    // Average number of fission neutrons produced (-nu)
    else if(strcmp(arg, "-nu") == 0){
      if(++i < argc) params->nu = atof(argv[i]);
      else print_error("Error reading command line input '-nu'");
    }

    // Absorption macro xs (-xs_a)
    else if(strcmp(arg, "-xs_a") == 0){
      if(++i < argc) params->xs_a = atof(argv[i]);
      else print_error("Error reading command line input '-xs_a'");
    }

    // Scattering macro xs (-xs_s)
    else if(strcmp(arg, "-xs_s") == 0){
      if(++i < argc) params->xs_s = atof(argv[i]);
      else print_error("Error reading command line input '-xs_s'");
    }

    // Fission macro xs (-xs_f)
    else if(strcmp(arg, "-xs_f") == 0){
      if(++i < argc) params->xs_f = atof(argv[i]);
      else print_error("Error reading command line input '-xs_f'");
    }

    // Geometry size in x (-x)
    else if(strcmp(arg, "-x") == 0){
      if(++i < argc) params->gx = atof(argv[i]);
      else print_error("Error reading command line input '-x'");
    }

    // Geometry size in y (-y)
    else if(strcmp(arg, "-y") == 0){
      if(++i < argc) params->gy = atof(argv[i]);
      else print_error("Error reading command line input '-y'");
    }

    // Whether to load source (-load_source)
    else if(strcmp(arg, "-load_source") == 0){
      if(++i < argc){
        if(strcasecmp(argv[i], "true") == 0)
          params->load_source = TRUE;
        else if(strcasecmp(argv[i], "false") == 0)
          params->load_source = FALSE;
        else
          print_error("Invalid option for parameter 'load_source': must be 'true' or 'false'");
      }
      else print_error("Error reading command line input '-load_source'");
    }

    // Whether to save source (-save_source)
    else if(strcmp(arg, "-save_source") == 0){
      if(++i < argc){
        if(strcasecmp(argv[i], "true") == 0)
          params->save_source = TRUE;
        else if(strcasecmp(argv[i], "false") == 0)
          params->save_source = FALSE;
        else
          print_error("Invalid option for parameter 'save_source': must be 'true' or 'false'");
      }
      else print_error("Error reading command line input '-save_source'");
    }

    // Whether to output tally (-write_tally)
    else if(strcmp(arg, "-write_tally") == 0){
      if(++i < argc){
        if(strcasecmp(argv[i], "true") == 0)
          params->write_tally = TRUE;
        else if(strcasecmp(argv[i], "false") == 0)
          params->write_tally = FALSE;
        else
          print_error("Invalid option for parameter 'write_tally': must be 'true' or 'false'");
      }
      else print_error("Error reading command line input '-write_tally'");
    }

    // Whether to output shannon entropy (-write_entropy)
    else if(strcmp(arg, "-write_entropy") == 0){
      if(++i < argc){
        if(strcasecmp(argv[i], "true") == 0)
          params->write_entropy = TRUE;
        else if(strcasecmp(argv[i], "false") == 0)
          params->write_entropy = FALSE;
        else
          print_error("Invalid option for parameter 'write_entropy': must be 'true' or 'false'");
      }
      else print_error("Error reading command line input '-write_entropy'");
    }

    // Whether to output keff (-write_keff)
    else if(strcmp(arg, "-write_keff") == 0){
      if(++i < argc){
        if(strcasecmp(argv[i], "true") == 0)
          params->write_keff = TRUE;
        else if(strcasecmp(argv[i], "false") == 0)
          params->write_keff = FALSE;
        else
          print_error("Invalid option for parameter 'write_keff': must be 'true' or 'false'");
      }
      else print_error("Error reading command line input '-write_keff'");
    }

    // Whether to output particle bank (-write_bank)
    else if(strcmp(arg, "-write_bank") == 0){
      if(++i < argc){
        if(strcasecmp(argv[i], "true") == 0)
          params->write_bank = TRUE;
        else if(strcasecmp(argv[i], "false") == 0)
          params->write_bank = FALSE;
        else
          print_error("Invalid option for parameter 'write_bank': must be 'true' or 'false'");
      }
      else print_error("Error reading command line input '-write_bank'");
    }

    // Whether to output source distribution (-write_source)
    else if(strcmp(arg, "-write_source") == 0){
      if(++i < argc){
        if(strcasecmp(argv[i], "true") == 0)
          params->write_source = TRUE;
        else if(strcasecmp(argv[i], "false") == 0)
          params->write_source = FALSE;
        else
          print_error("Invalid option for parameter 'write_source': must be 'true' or 'false'");
      }
      else print_error("Error reading command line input '-write_source'");
    }

    // Path to write tallies to (-tally_file)
    else if(strcmp(arg, "-tally_file") == 0){
      if(++i < argc){
        if(params->tally_file != NULL) free(params->tally_file);
        params->tally_file = malloc(strlen(argv[i])*sizeof(char)+1);
        strcpy(params->tally_file, argv[i]);
      }
      else print_error("Error reading command line input '-tally_file'");
    }

    // Path to write shannon entropy to (-entropy_file)
    else if(strcmp(arg, "-entropy_file") == 0){
      if(++i < argc){
        if(params->entropy_file != NULL) free(params->entropy_file);
        params->entropy_file = malloc(strlen(argv[i])*sizeof(char)+1);
        strcpy(params->entropy_file, argv[i]);
      }
      else print_error("Error reading command line input '-entropy_file'");
    }

    // Path to write keff to (-keff_file)
    else if(strcmp(arg, "-keff_file") == 0){
      if(++i < argc){
        if(params->keff_file != NULL) free(params->keff_file);
        params->keff_file = malloc(strlen(argv[i])*sizeof(char)+1);
        strcpy(params->keff_file, argv[i]);
      }
      else print_error("Error reading command line input '-keff_file'");
    }

    // Path to write bank to (-bank_file)
    else if(strcmp(arg, "-bank_file") == 0){
      if(++i < argc){
        if(params->bank_file != NULL) free(params->bank_file);
        params->bank_file = malloc(strlen(argv[i])*sizeof(char)+1);
        strcpy(params->bank_file, argv[i]);
      }
      else print_error("Error reading command line input '-bank_file'");
    }

    // Path to write source distribution to (-source_file)
    else if(strcmp(arg, "-source_file") == 0){
      if(++i < argc){
        if(params->source_file != NULL) free(params->source_file);
        params->source_file = malloc(strlen(argv[i])*sizeof(char)+1);
        strcpy(params->source_file, argv[i]);
      }
      else print_error("Error reading command line input '-source_file'");
    }

    // Unknown command line option
    else print_error("Error reading command line input");
  }

  // Validate Inputs
  if(params->write_tally == TRUE && params->tally_file == NULL)
    params->tally_file = "tally.dat";
  if(params->write_entropy == TRUE && params->entropy_file == NULL)
    params->entropy_file = "entropy.dat";
  if(params->write_keff == TRUE && params->keff_file == NULL)
    params->keff_file = "keff.dat";
  if(params->write_bank == TRUE && params->bank_file == NULL)
    params->bank_file = "bank.dat";
  if(params->write_source == TRUE && params->source_file == NULL)
    params->source_file = "source.dat";
  if(params->n_batches < 1 && params->n_generations < 1)
    print_error("Must have at least one batch or one generation");
  if(params->n_batches < 0)
    print_error("Number of batches cannot be negative");
  if(params->n_generations < 0)
    print_error("Number of generations cannot be negative");
  if(params->n_active > params->n_batches)
    print_error("Number of active batches cannot be greater than number of batches");
  if(params->n_bins < 0)
    print_error("Number of bins cannot be negative");
  if(params->nu < 0)
    print_error("Average number of fission neutrons produced cannot be negative");
  if(params->gx <= 0 || params->gy <= 0)
    print_error("Length of domain must be positive in x and y dimension");
  if(params->xs_f < 0 || params->xs_a < 0 || params->xs_s < 0)
    print_error("Macroscopic cross section values cannot be negative");

  return;
}

void print_error(char *message)
{
  printf("ERROR: %s\n", message);
  exit(1);
}

void print_params(Parameters *params)
{
  char *bc = NULL;
  if(params->bc == 0) bc = "Vacuum";
  else if(params->bc == 1) bc = "Reflective";
  else if(params->bc == 2) bc = "Periodic";
  border_print();
  center_print("INPUT SUMMARY", 79);
  border_print();
  printf("Number of particles:            "); fancy_int(params->n_particles);
  printf("Number of batches:              %d\n", params->n_batches);
  printf("Number of active batches:       %d\n", params->n_active);
  printf("Number of generations:          %d\n", params->n_generations);
  printf("Boundary conditions:            %s\n", bc);
  printf("Number of nuclides in material: %d\n", params->n_nuclides);
  printf("RNG seed:                       %d\n", params->seed);
  border_print();
}

void border_print(void)
{
  printf( "=========================================="
     "======================================\n");
}

// Prints comma separated integers - for ease of reading
void fancy_int(long a)
{
  if(a < 1000)
    printf("%ld\n",a);
  else if(a >= 1000 && a < 1000000)
    printf("%ld,%03ld\n", a/1000, a % 1000);
  else if(a >= 1000000 && a < 1000000000)
    printf("%ld,%03ld,%03ld\n", a/1000000, (a % 1000000)/1000, a % 1000);
  else if(a >= 1000000000)
    printf("%ld,%03ld,%03ld,%03ld\n", a / 1000000000,
       (a % 1000000000)/1000000, (a % 1000000)/1000, a % 1000);
  else
    printf("%ld\n",a);
}

// Prints Section titles in center of 80 char terminal
void center_print(const char *s, int width)
{
  int length = strlen(s);
  int i;
  for (i=0; i<=(width-length)/2; i++){
    fputs(" ", stdout);
  }
  fputs(s, stdout);
  fputs("\n", stdout);
}

void write_tally(Tally *t, FILE *fp, char *filename)
{
  int i, j;

  fp = fopen(filename, "a");

  for(i=0; i<t->n; i++){
    for(j=0; j<t->n; j++){
      fprintf(fp, "%e ", t->flux[i + t->n*j]);
    }
    fprintf(fp, "\n");
  }

  fclose(fp);

  return;
}

void write_entropy(double H, FILE *fp, char *filename)
{
  fp = fopen(filename, "a");
  fprintf(fp, "%.10f\n", H);
  fclose(fp);

  return;
}

void write_keff(double *keff, int n, FILE *fp, char *filename)
{
  int i;
  fp = fopen(filename, "a");

  for(i=0; i<n; i++){
    fprintf(fp, "%.10f\n", keff[i]);
  }

  fclose(fp);

  return;
}

void write_bank(Bank *b, FILE *fp, char *filename)
{
  int i;

  fp = fopen(filename, "a");

  for(i=0; i<b->n; i++){
    fprintf(fp, "%.10f %.10f ", b->p[i].x, b->p[i].y);
  }
  fprintf(fp, "\n");

  fclose(fp);
  return;
}

void write_source(Geometry *g, Bank *b, Parameters *params, FILE *fp, char *filename)
{
  int i, j;
  double dx, dy;
  unsigned long ix, iy;
  unsigned long l;
  unsigned long n;
  double *dist;
  Particle *p;

  // Number of grid boxes in each dimension
  n = params->n_bins;

  // Find grid spacing
  dx = g->x/n;
  dy = g->y/n;

  // Allocate array to keep track of number of sites in each grid box
  dist = calloc(n*n, sizeof(double));

  for(l=0; l<b->n; l++){
    p = &(b->p[l]);

    // Find the indices of the grid box of the particle
    ix = p->x/dx;
    iy = p->y/dy;

    dist[ix + n*iy]++;
  }

  // Normalize by number of particles
  for(l=0; l<n*n; l++){
    dist[l] /= b->n;
  }

  fp = fopen(filename, "a");

  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      fprintf(fp, "%e ", dist[i + n*j]);
    }
    fprintf(fp, "\n");
  }

  fclose(fp);

  free(dist);

  return;
}

void load_source(Bank *b)
{
  unsigned long stat;
  FILE *fp;

  fp = fopen("source.dat", "rb");
  if(fp == NULL){
    print_error("Couldn't open source file.");
  }
  stat = fread(b->p, sizeof(Particle), b->sz, fp);
  if(stat != b->sz){
    print_error("Error loading source.");
  }
  fclose(fp);

  return;
}

void save_source(Bank *b)
{
  unsigned long stat;
  FILE *fp;

  fp = fopen("source.dat", "wb");
  stat = fwrite(b->p, sizeof(Particle), b->n, fp);
  if(stat != b->n){
    print_error("Error saving source.");
  }
  fclose(fp);

  return;
}
