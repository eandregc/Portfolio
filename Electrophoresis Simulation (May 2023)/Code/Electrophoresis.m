classdef Electrophoresis < matlab.apps.AppBase

    % Properties that correspond to app components
    properties (Access = public)
        UIFigure                        matlab.ui.Figure
        masaParticula                   matlab.ui.control.NumericEditField
        VelocidaddelapartculaLabel_2    matlab.ui.control.Label
        velocidadParticula              matlab.ui.control.NumericEditField
        VelocidaddelapartculaLabel      matlab.ui.control.Label
        cargaParticula                  matlab.ui.control.NumericEditField
        CargaCenlaplacaderechaLabel_2   matlab.ui.control.Label
        Limpiar                         matlab.ui.control.Button
        Graficar                        matlab.ui.control.Button
        cargaDerecha                    matlab.ui.control.NumericEditField
        CargaCenlaplacaderechaLabel     matlab.ui.control.Label
        cargaIzquierda                  matlab.ui.control.NumericEditField
        CargaenlaplacaizquierdaLabel    matlab.ui.control.Label
        separacion                      matlab.ui.control.NumericEditField
        SeparacinentreplacasmEditFieldLabel  matlab.ui.control.Label
        alto                            matlab.ui.control.NumericEditField
        AltodelasplacasmEditFieldLabel  matlab.ui.control.Label
        Image                           matlab.ui.control.Image
        grafica                         matlab.ui.control.UIAxes
    end

    % Callbacks that handle component events
    methods (Access = private)

        % Button down function: grafica
        function graficaButtonDown(app, event)
            
        end

        % Button pushed function: Graficar
        function GraficarPushed2(app, event)
            % Solicitar los parámetros de entrada utilizando una interfaz gráfica
            altoPlacas = app.alto.Value;
            separacionPlacas = app.separacion.Value;
            cargaPlacaIzquierda = app.cargaIzquierda.Value;
            cargaPlacaDerecha = app.cargaDerecha.Value;
            % Calcular ancho de las placas iguales
            anchoPlacas = 1;
            
            % Crear la malla de puntos
            NumeroDeVectores = 55;
            MinX = -separacionPlacas;
            MaxX = separacionPlacas;
            MinY = -altoPlacas;
            MaxY = altoPlacas;
            lineaX = linspace(MinX, MaxX, NumeroDeVectores);
            lineaY = linspace(MinY, MaxY, NumeroDeVectores);
            [X,Y] = meshgrid(lineaX, lineaY);
            
            % Definir cantidad de cargas
            placaIzquierdaCargas = altoPlacas+1;
            placaDerechaCargas = (altoPlacas/2)+1;
            TotalDeCargas = (placaIzquierdaCargas) + (placaDerechaCargas);
            
            % Definir vector de centros 
            centrosX = zeros(size(placaIzquierdaCargas));
            centrosY = zeros(size(placaIzquierdaCargas));
            
            % Definir centros de las cargas 
            for i = 1:TotalDeCargas
                if i <= placaIzquierdaCargas
                % Definir centros de las cargas a traves de la placa izquierda
                centrosX(i) = (-anchoPlacas-separacionPlacas)/2;
                centrosY(i) = -i+1+altoPlacas/2;
                elseif i > placaIzquierdaCargas
                % Definir centros de las cargas a traves de la placa derecha
                centrosX(i) = (anchoPlacas+separacionPlacas)/2;
                centrosY(i) = -i+altoPlacas+7;
                end
            end
            
            % Constantes del campo electrico 
            eps0 = 8.854e-12;
            constanteK = 1/(4*pi*eps0);
            % Calcular campo eléctrico en cada punto de la cuadrícula
            ValorCampoX_total = zeros(size(X)); % Vector de ceros en X
            ValorCampoY_total = zeros(size(Y)); % Vector de ceros en Y
            
            % Recorrer la cuadrícula para sacar el campo eléctrico en la carga entre las placas
            for recorrerCargas = 1:TotalDeCargas
                % Calcular las direcciones a los respectivos origenes
                distanciaX = X - centrosX(recorrerCargas);
                distanciaY = Y - centrosY(recorrerCargas);
                desplazamiento = sqrt(distanciaX.^2 + distanciaY.^2).^3;
                if recorrerCargas <= placaIzquierdaCargas
                valorCampo = constanteK .* cargaPlacaIzquierda .* distanciaX ./ desplazamiento;
                ValorCampoX_total = ValorCampoX_total + valorCampo;
                valorCampo = constanteK .* cargaPlacaIzquierda .* distanciaY ./ desplazamiento;
                ValorCampoY_total = ValorCampoY_total + valorCampo;
                elseif recorrerCargas > placaIzquierdaCargas
                valorCampo = constanteK .* cargaPlacaDerecha .* distanciaX ./ desplazamiento;
                ValorCampoX_total = ValorCampoX_total + valorCampo;
                valorCampo = constanteK .* cargaPlacaDerecha .* distanciaY ./ desplazamiento;
                ValorCampoY_total = ValorCampoY_total + valorCampo;
                end
            end

            % Calcular las componentes X y Y del campo eléctrico en cada punto
            ValorCampoMagnitud = sqrt(ValorCampoX_total.^2 + ValorCampoY_total.^2);
            ValorCampoDireccionX = ValorCampoX_total ./ ValorCampoMagnitud;
            ValorCampoDireccionY = ValorCampoY_total ./ ValorCampoMagnitud;
            
            % Graficar la placa izquierda como una línea vertical
            rectangle(app.grafica,'Position',[(-1-separacionPlacas/2) 0-altoPlacas/2 anchoPlacas altoPlacas],'FaceColor','b','LineWidth',1);
            hold(app.grafica,'on')
            % Graficar la placa derecha como una línea vertical
            rectangle(app.grafica,'Position',[(0+separacionPlacas/2) 0-altoPlacas/2/2 anchoPlacas altoPlacas/2],'FaceColor','r','LineWidth',1);
            hold(app.grafica,'on')

            % Graficar el campo eléctrico total
            quiver(app.grafica,X, Y, ValorCampoDireccionX, ValorCampoDireccionY, 'autoscalefactor', 0.8, 'LineWidth', 1, 'Color', 'm');
            hold(app.grafica,'on')
            
            % CONDICIONES INICIALES DE LA PARTÍCULA DE MALARIA
            cargaDeParticula = 1e-19 * app.cargaParticula.Value; % Carga de la partícula de malaria en coulombs
            masaDeParticula = 1e-16 * app.masaParticula.Value; % Masa de la partícula de malaria en kg
            posicionInicial = [0,altoPlacas/2+5]; % Posición inicial de la partícula en metros
            velocidadInicial = -1*app.velocidadParticula.Value; % Velocidad inicial de la partícula en m/s

            % Simular trayectoria de la partícula en el campo eléctrico usando el método de Euler
            dt = 0.8; % tamaño de paso de tiempo
            t = 0; % tiempo inicial
            x = posicionInicial(1);
            y = posicionInicial(2);
            velocidad = velocidadInicial;

            % Calcular la fuerza eléctrica sobre la partícula cargada
            Fx = cargaDeParticula * ValorCampoDireccionX;
            Fy = cargaDeParticula * ValorCampoDireccionY;

            % Calcular la aceleración de la partícula
            ax = Fx / masaDeParticula;
            ay = Fy / masaDeParticula;

            % Crear una línea animada para la  sangre
            if cargaDeParticula > 0
                trayectoriaParticula = animatedline(app.grafica, 'Color', 'r', 'LineWidth', 1.5);
            else
                trayectoriaParticula = animatedline(app.grafica, 'Color', 'b', 'LineWidth', 1.5);
            end
            axis(app.grafica,[-separacionPlacas separacionPlacas (-altoPlacas/1.5) (altoPlacas/1.5)]);
            hold(app.grafica,'on')

            % Calcular la trayectoria por Euler 
            iteraciones = 105; % Iteraciones a realizar
            particulaX = zeros(1,iteraciones);
            particulaY = zeros(1,iteraciones);
            particulaX(1) = posicionInicial(1);
            particulaY(1) = posicionInicial(2);

            for i = 1:iteraciones
            % Evaluar el campo eléctrico en la ubicación de la partícula
            posicionXactual = interp2(X, Y, ValorCampoDireccionX, particulaX(i), particulaY(i), 'linear');
            posicionYactual = interp2(X, Y, ValorCampoDireccionY, particulaX(i), particulaY(i), 'linear');
            
            % Calcular la aceleración en la ubicación de la partícula
            aXactual = cargaDeParticula * posicionXactual / masaDeParticula;
            aYactual = cargaDeParticula * posicionYactual / masaDeParticula;
            
            % Calcular la ubicación de la partícula usando el método de Euler
            particulaX(i + 1) = particulaX(i) - velocidad * cos(atan2(aYactual, aXactual)) * dt;
            particulaY(i + 1) = particulaY(i) - velocidad * sin(atan2(aYactual, aXactual)) * dt;

            % Graficar la ubicación de la partícula y trazar la linea
            addpoints(trayectoriaParticula, particulaX(i + 1), particulaY(i + 1));
            drawnow;
            end
            
            % Establecer los límites del eje x e y
            axis(app.grafica,[-separacionPlacas separacionPlacas (-altoPlacas/1.5) (altoPlacas/1.5)]);
            hold(app.grafica,'off')
        end

        % Button pushed function: Limpiar
        function LimpiarPushed(app, event)
            % Interfaz de simulación de campo eléctrico en MATLAB con gráfica
            % Limpiar el workspace
            plot(app.grafica,1,1)

        end
    end

    % Component initialization
    methods (Access = private)

        % Create UIFigure and components
        function createComponents(app)

            % Get the file path for locating images
            pathToMLAPP = fileparts(mfilename('fullpath'));

            % Create UIFigure and hide until all components are created
            app.UIFigure = uifigure('Visible', 'off');
            app.UIFigure.Position = [100 100 640 480];
            app.UIFigure.Name = 'MATLAB App';

            % Create grafica
            app.grafica = uiaxes(app.UIFigure);
            app.grafica.MinorGridLineStyle = '-.';
            app.grafica.BoxStyle = 'full';
            app.grafica.ButtonDownFcn = createCallbackFcn(app, @graficaButtonDown, true);
            app.grafica.Position = [88 25 465 291];

            % Create Image
            app.Image = uiimage(app.UIFigure);
            app.Image.Position = [443 364 213 77];
            app.Image.ImageSource = fullfile(pathToMLAPP, 'quePro.jpg');

            % Create AltodelasplacasmEditFieldLabel
            app.AltodelasplacasmEditFieldLabel = uilabel(app.UIFigure);
            app.AltodelasplacasmEditFieldLabel.BackgroundColor = [0 0 0];
            app.AltodelasplacasmEditFieldLabel.HorizontalAlignment = 'center';
            app.AltodelasplacasmEditFieldLabel.FontColor = [1 1 1];
            app.AltodelasplacasmEditFieldLabel.Position = [24 449 166 22];
            app.AltodelasplacasmEditFieldLabel.Text = 'Alto de las placas (m):';

            % Create alto
            app.alto = uieditfield(app.UIFigure, 'numeric');
            app.alto.FontColor = [1 1 1];
            app.alto.BackgroundColor = [0 0 0];
            app.alto.Position = [198 447 33 26];
            app.alto.Value = 20;

            % Create SeparacinentreplacasmEditFieldLabel
            app.SeparacinentreplacasmEditFieldLabel = uilabel(app.UIFigure);
            app.SeparacinentreplacasmEditFieldLabel.BackgroundColor = [0 0 0];
            app.SeparacinentreplacasmEditFieldLabel.HorizontalAlignment = 'center';
            app.SeparacinentreplacasmEditFieldLabel.FontColor = [1 1 1];
            app.SeparacinentreplacasmEditFieldLabel.Position = [24 421 166 22];
            app.SeparacinentreplacasmEditFieldLabel.Text = 'Separación entre placas (m):';

            % Create separacion
            app.separacion = uieditfield(app.UIFigure, 'numeric');
            app.separacion.FontColor = [1 1 1];
            app.separacion.BackgroundColor = [0 0 0];
            app.separacion.Position = [198 419 34 26];
            app.separacion.Value = 10;

            % Create CargaenlaplacaizquierdaLabel
            app.CargaenlaplacaizquierdaLabel = uilabel(app.UIFigure);
            app.CargaenlaplacaizquierdaLabel.BackgroundColor = [0 0 0];
            app.CargaenlaplacaizquierdaLabel.HorizontalAlignment = 'center';
            app.CargaenlaplacaizquierdaLabel.FontColor = [1 1 1];
            app.CargaenlaplacaizquierdaLabel.Position = [242 449 173 22];
            app.CargaenlaplacaizquierdaLabel.Text = 'Carga en la placa izquierda:';

            % Create cargaIzquierda
            app.cargaIzquierda = uieditfield(app.UIFigure, 'numeric');
            app.cargaIzquierda.FontColor = [1 1 1];
            app.cargaIzquierda.BackgroundColor = [0 0 0];
            app.cargaIzquierda.Position = [424 447 30 26];
            app.cargaIzquierda.Value = -1;

            % Create CargaCenlaplacaderechaLabel
            app.CargaCenlaplacaderechaLabel = uilabel(app.UIFigure);
            app.CargaCenlaplacaderechaLabel.BackgroundColor = [0 0 0];
            app.CargaCenlaplacaderechaLabel.HorizontalAlignment = 'center';
            app.CargaCenlaplacaderechaLabel.FontColor = [1 1 1];
            app.CargaCenlaplacaderechaLabel.Position = [242 421 173 22];
            app.CargaCenlaplacaderechaLabel.Text = 'Carga en la placa derecha:';

            % Create cargaDerecha
            app.cargaDerecha = uieditfield(app.UIFigure, 'numeric');
            app.cargaDerecha.FontColor = [1 1 1];
            app.cargaDerecha.BackgroundColor = [0 0 0];
            app.cargaDerecha.Position = [424 419 30 26];
            app.cargaDerecha.Value = 1;

            % Create Graficar
            app.Graficar = uibutton(app.UIFigure, 'push');
            app.Graficar.ButtonPushedFcn = createCallbackFcn(app, @GraficarPushed2, true);
            app.Graficar.BackgroundColor = [0 0 0];
            app.Graficar.FontColor = [1 1 1];
            app.Graficar.Position = [120 331 111 28];
            app.Graficar.Text = 'Gráficar';

            % Create Limpiar
            app.Limpiar = uibutton(app.UIFigure, 'push');
            app.Limpiar.ButtonPushedFcn = createCallbackFcn(app, @LimpiarPushed, true);
            app.Limpiar.BackgroundColor = [0 0 0];
            app.Limpiar.FontColor = [1 1 1];
            app.Limpiar.Position = [24 331 72 28];
            app.Limpiar.Text = 'Limpiar';

            % Create CargaCenlaplacaderechaLabel_2
            app.CargaCenlaplacaderechaLabel_2 = uilabel(app.UIFigure);
            app.CargaCenlaplacaderechaLabel_2.BackgroundColor = [0 0 0];
            app.CargaCenlaplacaderechaLabel_2.HorizontalAlignment = 'center';
            app.CargaCenlaplacaderechaLabel_2.FontColor = [1 1 1];
            app.CargaCenlaplacaderechaLabel_2.Position = [242 394 173 22];
            app.CargaCenlaplacaderechaLabel_2.Text = 'Carga en la partícula:';

            % Create cargaParticula
            app.cargaParticula = uieditfield(app.UIFigure, 'numeric');
            app.cargaParticula.FontColor = [1 1 1];
            app.cargaParticula.BackgroundColor = [0 0 0];
            app.cargaParticula.Position = [424 392 30 26];
            app.cargaParticula.Value = 1;

            % Create VelocidaddelapartculaLabel
            app.VelocidaddelapartculaLabel = uilabel(app.UIFigure);
            app.VelocidaddelapartculaLabel.BackgroundColor = [0 0 0];
            app.VelocidaddelapartculaLabel.HorizontalAlignment = 'center';
            app.VelocidaddelapartculaLabel.FontColor = [1 1 1];
            app.VelocidaddelapartculaLabel.Position = [134 366 174 22];
            app.VelocidaddelapartculaLabel.Text = 'Velocidad de la partícula(m/s):';

            % Create velocidadParticula
            app.velocidadParticula = uieditfield(app.UIFigure, 'numeric');
            app.velocidadParticula.FontColor = [1 1 1];
            app.velocidadParticula.BackgroundColor = [0 0 0];
            app.velocidadParticula.Position = [326 364 30 26];
            app.velocidadParticula.Value = 1;

            % Create VelocidaddelapartculaLabel_2
            app.VelocidaddelapartculaLabel_2 = uilabel(app.UIFigure);
            app.VelocidaddelapartculaLabel_2.BackgroundColor = [0 0 0];
            app.VelocidaddelapartculaLabel_2.HorizontalAlignment = 'center';
            app.VelocidaddelapartculaLabel_2.FontColor = [1 1 1];
            app.VelocidaddelapartculaLabel_2.Position = [24 394 166 22];
            app.VelocidaddelapartculaLabel_2.Text = 'Masa de la partícula(kg):';

            % Create masaParticula
            app.masaParticula = uieditfield(app.UIFigure, 'numeric');
            app.masaParticula.FontColor = [1 1 1];
            app.masaParticula.BackgroundColor = [0 0 0];
            app.masaParticula.Position = [198 392 34 26];
            app.masaParticula.Value = 3;

            % Show the figure after all components are created
            app.UIFigure.Visible = 'on';
        end
    end

    % App creation and deletion
    methods (Access = public)

        % Construct app
        function app = Electrophoresis

            % Create UIFigure and components
            createComponents(app)

            % Register the app with App Designer
            registerApp(app, app.UIFigure)

            if nargout == 0
                clear app
            end
        end

        % Code that executes before app deletion
        function delete(app)

            % Delete UIFigure when app is deleted
            delete(app.UIFigure)
        end
    end
end