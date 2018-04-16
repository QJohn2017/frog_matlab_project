clear

global hCamera
global position
global position_outer
global pbyteRaw
global dwBufferSize
global dwNumberOfByteTrans
global dwFrameNo
global dwMilliseconds
global BG_threshhold
global phase
global frame_avg_num
global dwWidth
global dwHeight
global initial_image
global current_image
global delay
global dwTriggerMode
global best_order_vals
global best_quality
global X0
global UB
global LB
global generations
global population_size
global best_image


disp('hello world')

delay = 1;
phase = 4350; % phase (delay) remains constant during optimization

% parameters
BG_threshhold = 0; 
frame_avg_num = 1;

% trigger mode
dwTriggerMode = 2049;

%initial parameters
X0 = [-7300, -30e3, 0];
%X0 = [-8500, -0.25e5, 0.5e5];

% variables: [order2, order3, order4]
% UB = [-8000, 0, 1.5e5];
% LB = [-9000, -0.5e5, -0.5e5];
UB = [-5000, 0.5e5, 1000];
LB = [-9000, -0.5e5, -1000];
generations = 15;
population_size = 100;

% initialize some values
current_image = 0;
best_quality = 0;
best_order_vals = 0;
best_image = 0;


%%%%% run main program %%%%
prepare_camera()

% send initial info to dazzler
dazzler_phase(phase, X0(1), X0(2), X0(3));
pause(delay)

% take the first image and draw the boxes
get_boxes()

% prepate genetic algorithm
options = gaoptimset('InitialPopulation',X0,'Generations',generations,'PopulationSize',population_size,'PlotFcns',@gaplotbestfun);

nvars = 3;    % Number of variables
IntCon = 1:3;
start_log()
x = ga(@beam_optimize, nvars, [], [], [], [], LB, UB, [], IntCon, options);

%%send the best values to the dazzler
disp('sending best quality parameters to dazzler: ')
disp(best_order_vals);
dazzler_phase(phase, best_order_vals(1), best_order_vals(2), best_order_vals(3));
pause(delay)


save('final.dat', 'current_image', '-ascii');
save('initial.dat', 'initial_image', '-ascii');
save('best.dat', 'best_image', '-ascii');
calllib('StTrgApi','StTrg_Close',hCamera);
