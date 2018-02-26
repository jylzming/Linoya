import QtQuick 2.5
import QtLocation 5.6
import QtQuick.Window 2.0
import QtPositioning 5.6

Rectangle{
    id: miniMapRect
    anchors.fill: parent
    color: "#242424"
    Map {
        id: miniMap
        anchors.fill: parent
        zoomLevel: (map.zoomLevel > minimumZoomLevel + 3) ? minimumZoomLevel + 3 : 2.5
        center: map.center
        plugin: map.plugin
        gesture.enabled: false
        copyrightsVisible: false
        Plugin {
            id: mapPlugin
            name: "osm" // "mapboxgl", "esri", ...
        }
        Map {
            anchors.fill: parent
            plugin: mapPlugin
            center: QtPositioning.coordinate(59.91, 10.75) // Oslo
            zoomLevel: 14
        }
    }
}
