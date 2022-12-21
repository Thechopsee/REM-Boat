#include "navcommand.hh"
    NavCommand::NavCommand(Nav_module * module)
    {
        this->module=module;
    }
    std::string NavCommand::renderMessage()
    {
        std::string data="";
        std::string dataa=this->module->getData();
        std::stringstream ss(dataa);
        std::string world;
        getline(ss,world,';');
        std::string latitude=world;
        getline(ss,world,';');
        std::string longitude=world;
        data.append("function start(){var map = new ol.Map({target: \"map\",layers: [new ol.layer.Tile({source: new ol.source.OSM()})],view: new ol.View({center: ol.proj.fromLonLat([");
            data.append(longitude);
            data.append(",");
            data.append(latitude);
            data.append("]),zoom:17 })});");
            data.append("var markers = new ol.layer.Vector({");
            data.append("source: new ol.source.Vector(),style: new ol.style.Style({image: new ol.style.Icon({anchor: [0.5, 1],src: 'https://icons-for-free.com/download-icon-map+marker+icon-1320166582858325800_48.png'})})});");
            data.append("map.addLayer(markers);");

            data.append("var marker = new ol.Feature(new ol.geom.Point(ol.proj.fromLonLat([");
            data.append(longitude);
            data.append(",");
            data.append(latitude);
            data.append("])));");
            data.append("markers.getSource().addFeature(marker);");
            data.append("}");
            return data;
    }
